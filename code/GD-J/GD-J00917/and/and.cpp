#include<bits/stdc++.h>
using namespace std;
const int N=3e5+10;
long long n,m,a[N],ans=0;
vector<long long> t[40],jg,js;
void dfs(int step,long long cnt,int id){
	if(cnt<ans)return;
	if(m-step>n-id+2)return;
	if(step>m){
		ans=max(ans,cnt);
		return;
	}
	for(int i=id;i<=n;i++){
		if(cnt==-1) dfs(step+1,a[i],i+1);
		else
		dfs(step+1,cnt&a[i],i+1);
		
	}
}
void solve(){
	for(int i=1;i<=n;i++){
		cin>>a[i];
		
	}
	if(n<=20){
		dfs(1,-1,1);
		cout<<ans;
	}else if(m==1){
		for(long long i=1;i<=n;i++)ans=max(ans,i);
		cout<<ans;
	}else if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				ans=max(ans,a[i]&a[j]);
			}
		}
		cout<<ans;
	}
	else{
		ans=2e18;
		for(long long i=1;i<=n;i++)ans=min(ans,i);
		cout<<ans;
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	solve();
	return 0;
} 
