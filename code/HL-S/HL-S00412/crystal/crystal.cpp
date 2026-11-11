#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[1000000],c,j=1;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=m;i++){
		//cout<<i<<" ";
		if((a[1]+a[j])*i/2<=m){
			if((a[1]+a[j+1])*(i+1)/2>m){
				cout<<i+1;
			}
		}
		j++;
	}
	return 0;
}
