#include<bits/stdc++.h>
using namespace std;
const int N=2010;
int n,m;
int a[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int ans=0;
	int maxx=-1;
	for(int l=0;l<n-m+1;l++){
		int r=l+m-1;
		for(int i=l;i<r;i++){
			int u=a[l];
			u=u&a[i+1];
			ans=u;
		}
		maxx=max(maxx,ans);
	}
	cout<<ans;
	return 0;
}
