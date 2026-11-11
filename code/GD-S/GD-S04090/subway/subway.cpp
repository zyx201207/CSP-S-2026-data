#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
long int w[501],a[500001],t[500001],x[100001],y[100001];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	long int c,n,m,d,q,r;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int o=1;o<=k;o++){
			cin>>a[o]>>t[o];
		}
	}
	for(int i=1;i<=q;i++){
		cin>>x[i]>>y[i];
	}
	for(int o=1;o<=q;o++){
	r=100000;
	
	cout<<a[o]+t[o]<<endl;	
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
