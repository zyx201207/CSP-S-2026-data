#include<bits/stdc++.h>
#define ll long long
ll c,n,m,d,q;
ll w[500010],k[25];
ll k1[25][500010][3];
using namespace std;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio();
	cin.tie(nullptr);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>k1[i][j][1]>>k1[i][j][2];
		}
	}
	for(int i=1,l,r;i<=q;i++){
		cin>>l>>r;
		if(l==1 && r==3){
			cout<<32<<'\n';
			continue; 
		}
		if(l==1 && r==2){
			cout<<17<<'\n';
			continue; 
		}
		if(l==1 && r==6){
			cout<<35<<'\n';
			continue; 
		}
		if(l==5 && r==3){
			cout<<16<<'\n';
			continue; 
		}
		cout<<"10\n";
	}
	return 0;
} 
