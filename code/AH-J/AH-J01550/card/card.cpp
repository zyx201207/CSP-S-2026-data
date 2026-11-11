#include<bits/stdc++.h>
using namespace std;
#define int long long
vector<pair<int,int>>vec;
int n,m;
int a[500010],ans[300010];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]<=m)ans[a[i]]=i;
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
	return 0;
}
