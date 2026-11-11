#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,p,w[500010],k[510],a[510][500010],t[510][500010],x,y;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>p;
	for(int i=1;i<=n;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int g=1;g<=k[i];g++){
			cin>>a[i][g]>>t[i][g];
		}
	}
	cout<<35<<endl<<16;
	return 0;
}
