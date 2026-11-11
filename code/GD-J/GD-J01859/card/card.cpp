#include<bits/stdc++.h>
using namespace std;
const int inf=0x3f3f3f3f;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	vector<int>a(n+1);
	vector<int>nxt(n+1,inf);
	vector<int>ans(m+1,0);
	for(int i=1;i<=n;i++)cin>>a[i];
	{
		vector<int>pos(m+1,inf);
		for(int i=n;i>=1;i--){
			nxt[i]=pos[a[i]];
			pos[a[i]]=i;
		}
	}
	{
		vector<int>c(n+1,1);
		for(int i=1;i<n;i++){
			c[nxt[i]==inf?i+1:nxt[i]]+=c[i];
		}
		for(int i=1;i<=n;i++)ans[a[i]]=c[i];
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<' ';
	return 0;
} 
