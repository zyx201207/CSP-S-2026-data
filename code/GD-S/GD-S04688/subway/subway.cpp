#include<bits/stdc++.h>
using namespace std;
int w[1000086],x[1000086],y[1000086];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k,a[10086],t[10086];
		cin>>k;
		for(int i=1;i<=k;i++){
			cin>>a[i]>>t[i]; 
		}
	}
	for(int i=1;i<=q;i++){
		cin>>x[i]>>y[i];
		cout<<x[i]+y[i];
	}
} 
