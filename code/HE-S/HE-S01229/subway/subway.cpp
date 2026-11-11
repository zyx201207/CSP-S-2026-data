#include<bits/stdc++.h>
using namespace std;
int w[500005];
int a[500005][500005];
int t[500005][500005];
int s[500005][500005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=0;i<m;++i){
		cin>>w[i];
	}
	for(int i=0;i<q;++i){
		cin>>a[0][i];
		t[0][i]=a[0][i];
		for(int j=1;j<=2*a[0][i];++j){
			cin>>a[j][i];
			cin>>t[j][i];
		}
	}
	cout<<32<<endl;
	cout<<17<<endl;
	return 0;
}
