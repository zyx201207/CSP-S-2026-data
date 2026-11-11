
#include <bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int v[N],ans,n,m;
bool st[N];
void dfs(int dep,int s){
	if(dep>m) {
		ans=max(ans,s);
		return ;
	}
	for(int i=1;i<=n;i++){
		if(st[i]==false){
			st[i]=true;
			if(dep==1) dfs(2,v[i]);
			else dfs(dep+1,s&v[i]);
			st[i]=false;
		}
	}
}
int main()
{
	ios::sync_with_stdio(0),cin.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>v[i];
	if(m==1) {
		for(int i=1;i<=n;i++) ans=max(ans,v[i]);
	}
	else if(m==n){
		ans=v[1];
		for(int i=1;i<=n;i++) ans&=v[i];
	}
	else if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				int x=v[i]&v[j];ans=max(ans,x);
			}
		}
	}
	else if(m==n-1){
		for(int i=1;i<=n;i++){
			int x=v[1];
			if(i==1) x=v[2];
			for(int j=1;j<=n;j++){
				if(j!=i) x&=v[i]; 
			}
			ans=max(ans,x);
		}
	}
	else if(n<=25){
		dfs(1,0);
	}
	else{
		ans=2147483647;
		for(int i=1;i<=n;i++) ans=min(ans,v[i]); 
	}
	cout<<ans;
	return 0;
}

