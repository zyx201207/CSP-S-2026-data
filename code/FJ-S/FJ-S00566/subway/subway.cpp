#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,w[510000],t[510000],u[510000],v1,v2;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>t[i]>>u[i];
		v1+=t[i];
		v2+=u[i];
	}
	for(int i=1;i<=2;i++){
		int x,y;
		cin>>x>>y;
	}
	cout<<v1<<v2<<endl;
	return 0;
}
