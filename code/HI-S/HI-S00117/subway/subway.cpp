#include<bits/stdc++.h>
using namespace std;
int C,n,m,d,q,k,s,e;
int a[20005],b[20005],c[20005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>C>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>b[j]>>c[j];
			c[j]+=a[j];
		}
		sort(c+1,c+k+1);
	}
	for(int i=1;i<=q;i++){
		cin>>s>>e;
		cout<<c[s]+c[e]<<'\n';
	}
	return 0;
}
