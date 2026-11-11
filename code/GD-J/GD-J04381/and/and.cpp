#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
const int M=1e2+10;
const int INF=0x3f3f3f3f;
int n,m;
int a[N];
int e[N][M];
int maxx;
signed main(){
	   freopen("and.in","r",stdin);
	   freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		int a1=a[i];
		maxx=max(maxx,a[i]);
	}
	if(m==1)
	cout<<maxx;
	else{
		maxx=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				maxx=max(maxx,a[i]&a[j]);
			}
		}
		cout<<maxx;
	}
	return 0;
}

