//GZ-S00293 遵义市第四中学 杨宜炜
#include<bits/stdc++.h>
using namespace std;
int c,n,m,sum,d,q,tmp,tpm,u,v,a[500010];
vector<int> No[510];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=0;i<m;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		cin>>tmp;
		for(int j=0;j<tmp;j++){
			cin>>v>>tpm;
			No[i].push_back(v);
			sum+=tpm;
		}
	}
	for(int i=0;i<q;i++){
		cin>>u>>v;
	}
	cout<<sum*2;
}
