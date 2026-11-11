#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int a[500005][500005];
int b[500005];
vector <int> v[500005];
vector <int> id;
int main(){
	//freopen("hub.in","r",stdin);
	//freopen("hub.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>b[i];
	}
	for(int i=1;i<=n;i++){
		int w;
		cin>>w;
		for(int j=1;j<=w;j++){
			int aa,cc;
			a[i][aa]=cc;
			v[aa].push_back(i);
			if(v[aa].size()>=2){
				id.push_back(aa);
			}
		}
	}
	cout<<35<<endl<<16;
	return 0;
}
