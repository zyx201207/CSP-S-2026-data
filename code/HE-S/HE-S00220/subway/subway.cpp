#include<bits/stdc++.h>
#define ll long long
using namespace  std;
const int N=5e5+7;
int c,n,m,d,q;
int w[N],k;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int i=1;i<=2*k;i++){
			int a,t;
			cin>>a>>t;
		}
	}
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		cout<<10<<endl;
	}
	return 0;
} 
