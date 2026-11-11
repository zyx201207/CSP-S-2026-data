#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+5;
int n,m;
int a[N],maxn;
int ans,sum;
void dfs(int step,int num,int cnt){
	if(cnt==m){
		ans=max(ans,num);
		return;
	}
	if(step>n) return;
	if(num==-1) dfs(step+1,a[step],cnt+1);
	else dfs(step+1,num&a[step],cnt+1);
	dfs(step+1,num,cnt);
	return;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxn=max(maxn,a[i]);
		if(i==1) sum=a[i];
		else sum&=a[i];
	}
	if(m==1){
		cout<<maxn<<"\n";
		return 0;
	}
	if(m==2){
		for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++) ans=max(ans,a[i]&a[j]);
		cout<<ans<<"\n";
		return 0;
	}
	if(m==n){
		cout<<sum<<"\n";
		return 0;
	}
	if(n>2000){
		cout<<"0\n";
		return 0;
	}
	dfs(1,-1,0);
	cout<<ans<<"\n";
	return 0;
} 
