#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[200005],s[200005],fs[200005],maxa,maxb,ans;
void dfs(int step,long long num,int id){
	if(step==m){
		ans=max(ans,num);
		return ;
	}
	if(id>=n){
		return ;
	}
	if(step==0){
		dfs(step+1,a[id+1],id+1);
		dfs(step,num,id+1);
	}
	else{
		dfs(step+1,num & a[id+1],id+1);
		dfs(step,num,id+1);
	}
}
bool check(int k){
	while(k%2==0){
		k/=2;
	}
	if(k==1){
		return 1;
	}
	return 0;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxa=max(a[i],maxa);
		if(a[i]==1){
			s[1]=a[1];
		}
		else{
			s[i] = s[i-1] & a[i];
		}
	}
	if(m==1){
		cout<<maxa;
		return 0;
	}
	if(m==2){
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				maxb=max(maxb,a[i] & a[j]);
			}
		}
		cout<<maxb;
		return 0;
	}
	if(m==n){
		cout<<s[n];
		return 0;
	}
	if(maxa<4){
		int sum[4]={0,0,0,0};
		for(int i=1;i<=n;i++){
			sum[a[i]]++;
		}
		if(sum[3]>=m){
			cout<<3;
		}
		else if(sum[2]>=m || sum[2] + sum[3]>=m){
			cout<<2;
		}
		else if(sum[1]>=m || sum[1] + sum[3]>=m){
			cout<<1;
		}
		else{
			cout<<0;
		}
		return 0;
	}
	if(m==n-1){
		fs[n]=a[n];
		for(int i=n-1;i>=1;i--){
			fs[i] = fs[i+1] & a[i];
		}
		long long ansa=0;
		for(int i=1;i<=n;i++){
			ansa=max(ansa,s[i-1]+fs[i+1]);
		}
		cout<<ansa;
		return 0;
	}
	if(check(n)){
		if(n/2<m){
			cout<<0;
		}
		else{
			cout<<n/2;
		}
		return 0;
	}
	if(n<=20){
		dfs(0,0,0);
		cout<<ans;
		return 0;
	}
	sort(a+1,a+n+1);
	cout<<a[1];
	return 0;
}
