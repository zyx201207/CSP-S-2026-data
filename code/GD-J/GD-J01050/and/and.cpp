#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5;
int n,m,a[N],ma,ans=INT_MAX,b0[N],b1[N];
bool b=0;
void dfs(int i,int k,int &ans,int cnt){
	if(cnt==m){
		if(k!=INT_MAX)ans=max(k,ans);
		return ;	
	}
	if(i==n+1)return ;
	dfs(i+1,k&a[i+1],ans,cnt+1);
	dfs(i+1,a[i+1],ans,cnt);
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		ma=max(a[i],ma);
		ans=ans&a[i];
		b0[i]=b0[i-1]&a[i];
		bool bo=0;
		int now=1;
		for(int i=1;i<=30;i++){
			if(now-1==a[i]){
				bo=1;	
				break;
			}
			now*=2;
		}
		if(!bo)b=1;
	}
	for(int i=1;i<=n;i++)b1[i]=b1[i+1]&a[i];
	if(m==1)cout<<ma;
	else if(!b){
		sort(a+1,a+n+1);
		cout<<a[n-m+1];
	}else if(m==n)cout<<ans;
	else if(m==2){
		ans=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i!=j)ans=max(ans,a[i]&a[j]);
			}
		}
		cout<<ans;
	}else if(m==n-1){
		ans=0;
		for(int i=1;i<=n;i++){
			ans=max(ans,b0[i-1]&b1[i+1]);
		}
		cout<<ans;
	}else{
		ans=0;
		dfs(0,INT_MAX,ans,0);
		cout<<ans;
	}
	return 0;
}

