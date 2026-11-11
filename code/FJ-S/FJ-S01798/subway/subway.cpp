#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
int mv[500005];
int na[505][500005];
int nt[505][500005];
int cg[505][505];
int w[500005];
int n,m,d,q;

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c=0;
	cin>>c;
	cin>>n>>m>>d>>q;
	for(int i=0;i<m;i++){
		cin>>mv[i];
	} 
	for(int j=0;j<n;j++){
		cin>>w[j];
		for(int i=0;i<w[j];i++){
			cin>>na[j][i]>>nt[j][i];
		} 
	}
	for(int qe=0;qe<q;qe++){
		int st,en;
		cin>>st>>en;
		int ans=0;
		ans=mv[st]+mv[en];
		if(st==en){
			cout<<0;
		}
		ans+=nt[0][0]*2;
		cout<<ans<<endl;
		ans=0; 
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
