#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[200005],qzh[200005],dp[200005],mx=LLONG_MIN;
void dfs(int k,int now,int cnt,bool b,string ans){ 
	if(k>n)return ;
	if(b==0){
		dfs(k+1,(now&a[k+1]),cnt+1,1,ans);
		dfs(k+1,now,cnt,0,ans);
		return ;
	}
	if(now==0)now=a[k];
//ต๗สิว๘ 
//	cout<<k<<' '<<now<<' '<< cnt<<'\n';
//	ans+=(char)(a[k]);

//	cout<<a[k]<<' '<<now<<' '<<(now&a[k])<<'\n';
	if(cnt==m){
		mx=max(mx,(now&a[k]));
		//cout<<mx<<'\n'<<now<<'\n';
//		for(int i=0;i<ans.size();i++){
//			cout<<(int)(ans[i])<<' ';
//		}
//		cout<<'\n';
		return ;
	}
	dfs(k+1,now,cnt,0,ans);
	now=(now&a[k]);
	dfs(k+1,now,cnt+1,1,ans);
	
}
signed main(){

	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		
	}
	if(n==m){
		for(int i=1;i<=n;i++)
		mx=(mx&a[i]);
		cout<<mx;
		return 0;
	}
	if(m==1){
		for(int i=1;i<=n;i++){
			mx=max(mx,a[i]);
		}cout<<mx;
		return 0;
	}
	dfs(1,a[1],1,1,"");
	dfs(1,a[1],0,0,"");
	cout<<mx;
	return 0;
}
