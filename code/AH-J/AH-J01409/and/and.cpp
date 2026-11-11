#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int a[N],n,m,ans;
void dfs(int d,int v,int cnt){
	if(cnt>m){
		ans=v;
		return;
	}
	for(int i=1;i<=n;i++){
		v=a[i];
		for(int j=i+1;j<=n;j++){
			dfs(d+1,(v&a[j]),++cnt);
			dfs(d+1,v,cnt);

		}

	}
}

int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(1,0,0);
	cout<<ans;
	return 0;
} 
