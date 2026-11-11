#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,zds,qd,mdd;
int a[50000];
struct p{
	int a;
	int b;
} b[50000];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>a[i]; 
	}
	for(int i=1;i<=m;i++){
		cin>>zds;
		for(int j=1;j<=zds;j++){
		cin>>b[j].a>>b[j].b;
	}
	
	}
	for(int i=1;i<=q;i++){
		cin>>qd>>mdd;
	}
	return 0;
}
