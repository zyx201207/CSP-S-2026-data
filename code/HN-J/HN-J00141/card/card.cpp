#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[500100];
int ans[500100];
int f[500100];
int t[500100];
int t2[500100];
int ft[500100];
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0); 
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		t[a[i]]++;
		ft[a[i]]++;
	} 
	for(int i=1;i<=n;i++){
		t2[a[i]]++;
		if(t[a[i]]==t2[a[i]]){
			ans[a[i]]+=ft[a[i]];
			ft[a[i+1]]+=ft[a[i]];
		}
	}
	for(int i=1;i<=m;i++)
	cout<<ans[i]<<" ";
	return 0;
}

