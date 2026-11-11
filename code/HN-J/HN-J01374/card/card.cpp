#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e5+5;
int n,m;
int a[N];
bool vis[N];
int ans=0;
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	int mx=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=m;i++)
		cout<<a[i];
	return 0;
}
