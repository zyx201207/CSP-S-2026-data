#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,m,a[N],vis[N],sum;
void dfs(int now,int step){
	if(step==0) sum=max(sum,now);
	for(int i=1;i<=n;i++){
		if(vis[i]==1) continue;
		vis[i]=1;
		dfs(now&a[i],step-1);
		vis[i]=0;
	}
}
int fc(int x,int y,int now,int k){
	if(x/2>=y) return fc(x/2,y,k*2+now,k*2);
	else return now;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	bool flag=true,flagb=true;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>=4) flag=false;
		if(a[i]!=i-1) flagb=false;
	}
	if(n<=20){
		for(int i=1;i<=n;i++){
			vis[i]=1;
			dfs(a[i],m-1);
			vis[i]=0;
		}
		cout<<sum; 
	}//测试点1~5-25分 
	else if(m==1){
		sort(a+1,a+1+n);
		cout<<a[n];
	}//测试点6-5分
	else if(m==n){
		int ans=a[1];
		for(int i=2;i<=n;i++) ans=ans&a[i];
		cout<<ans;
	}//测试点7-5分
	else if(m==2){
		int ans=0;
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				ans=max(ans,a[i]&a[j]);
		cout<<ans; 
	}//测试点8~10-15分
	else if(flag==true){
		int ansa=0,ansb=0,ansc=0,ansd=0;
		for(int i=1;i<=n;i++){
			if(a[i]==3) ansa++;
			if(a[i]==2) ansb++;
			if(a[i]==1) ansc++;
			if(a[i]==0) ansd++;
		}
		if(ansa>=m) cout<<3;
		else if(ansa+ansb>=m) cout<<2;
		else if(ansa+ansc>=m) cout<<1;
		else cout<<0; 
	}//测试点16~17-10分 
	else if(flagb==true){
		int mi=0,ni=n;
		while(ni!=1) ni/=2,mi++;
		if(pow(2,mi-1)==m||(m>pow(2,mi-1)/2&&m<pow(2,mi-1))) cout<<pow(2,mi-1);
		else if(pow(2,mi-1)/2>=m) cout<<pow(2,mi-1)+fc(pow(2,mi-1)/2,m,1,1);
		else cout<<0;
	}//特殊样例B-10分 
	else{
		sort(a+1,a+1+n);
		int ans=a[n];
		for(int i=n-1;i>=n-m+1;i--) ans=ans&a[i];
		cout<<ans;
	}//特殊样例A-5分 
	return 0;
}

