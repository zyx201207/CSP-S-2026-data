#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int w[N];
int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	int a,t;
	int x,y;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	int k;
	cin>>k;
	for(int i=1;i<=k;i++){
		cin>>a;
		for(int j=1;j<=k;j++){
			cin>>t;
		}
	}
	int r;
	cin>>r;
	for(int i=1;i<=r;i++){
		cin>>x>>y;
	}
	return 0;
} 
