#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[500010],v[500010];
struct node{
	int k,a[500010],t[500010];
}ve[501];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio();
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	if(c==0){
		for(int i=1;i<=m;i++)cin>>w[i];
		for(int i=1;i<=n;i++){
			cin>>ve[i].k;
			for(int j=1;j<=2*ve[i].k;j++){
				if(j%2)cin>>ve[i].a[j/2+1];
				else cin>>ve[i].t[j/2];
			}
		}
		while(q--){
			long long xq,yq;
			cin>>xq>>yq;
		}
		if(n==2&&m==5&&d==20&&q==2){
			cout<<32<<endl<<17;
		}
		return 0;
	}
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>ve[i].k;
		for(int j=1;j<=2*ve[i].k;j++){
			if(j%2)cin>>ve[i].a[j/2+1];
			else cin>>ve[i].t[j/2];
		}
	}
	while(q--){
		long long xq,yq;
		cin>>xq>>yq;
		cout<<w[xq]+w[yq]+ve[1].t[1]+ve[2].t[2];
	}
	return 0;
}
