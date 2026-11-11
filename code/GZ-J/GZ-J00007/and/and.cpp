//GZ-J00007,裘滨溪,贵阳市第一中学
#include<bits/stdc++.h>
using namespace std;
long long a[200005];
long long ans=0;
int n,m;
void dfs(int cnt,int idx,long long val){
	if(cnt==m){
		ans=max(ans,val);
		return;
	}
	for(int i=idx;i<=n;i++){
		dfs(cnt+1,i+1,val&a[i]);
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	long long val1=0,valn=(1LL<<40)-1;
	bool fff=true;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		val1=max(val1,a[i]),valn=valn&a[i];
		int num=1.0*log(a[i]+1.0)/log(2.0);
		if(fff && num*1.0!=1.0*log(a[i]+1.0)/log(2.0)){
			fff=false;
		}
	}
	if(n<=20 || m==2){
		dfs(0,1,(1LL<<40)-1);
		cout<<ans;
		return 0;
	}
	if(m==1){
		cout<<val1;
		return 0;
	}
	if(m==n){
		cout<<valn;
		return 0;
	}
	if(fff){
		sort(a+1,a+n+1);
		cout<<a[n-m+1]; 
	}
	return 0;
}
