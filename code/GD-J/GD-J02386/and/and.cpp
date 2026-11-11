#include<bits/stdc++.h>
using namespace std;
int n,m,a[200010],ans=-1,fori[200010];
bool Atag=1,Btag=1,alllower4tag=1;
bool check(int n){
	for(int i=1;i<32;i++)if(n==1<<i-1)return 1;
	return 0;
}
int dfs(int t,int tmp){
	int res=-1;
	if(t==0)return tmp; 
	for(fori[t]=fori[t+1]+1;fori[t]<=n;fori[t]++)res=max(res,dfs(t-1,tmp&a[fori[t]]));
	return res;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		Atag&=check(a[i]),Btag&=(a[i]==i-1),alllower4tag&=(a[i]<4);
	}
	sort(a+1,a+n+1);
	if(m==1)ans=a[n];//for 6
	else if(m==2){//for 8~10
		for(int i=1;i<n;i++)
			for(int j=i+1;j<=n;j++)
				ans=max(ans,a[i]&a[j]);
	}else if(m==n){//for 7
		int tmp=2147483647;
		for(int i=1;i<=n;i++)tmp&=a[i];
		ans=tmp; 
	}else if(m==n-1){//for 11,12
		for(int i=1;i<=n;i++){
			int tmp=2147483647;
			for(int j=1;j<=n;j++){
				if(i==j)continue;
				tmp&=a[j];
			}
			ans=max(ans,tmp);
		}
	}else if(Atag){//for 13
		int tmp=2147483647;
		for(int i=n;i>n-m;i--)tmp&=a[i];
		ans=tmp; 
	}else if(Btag)ans=n-m;//for 14,15
	else if(alllower4tag){//for 16,17
		int num1,num2,num3;
		for(int i=1;i<=n;i++){
			if(a[i]==1)num1++;
			if(a[i]==2)num2++;
			if(a[i]==3)num3++;
		}
		if(num3>=m)ans=3;
		else if(num3+num2>=m)ans=2;
		else if(num3+num1>=m)ans=1;
		else ans=0;
	}
	else ans=dfs(m,2147483647);//for else
	cout<<ans;
	return 0;
}
