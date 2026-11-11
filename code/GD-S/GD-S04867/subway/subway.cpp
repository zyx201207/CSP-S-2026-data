#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,e,r;
int w[500005],a[505][1005],t[505][1005],x,y;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=0;i<m;i++) cin>>w[i];
	for(int i=0;i<n;i++){
		cin>>a[i][0];
		for(int j=1;j<=a[i][0];j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	for(int i=0;i<q;i++){
		cin>>x>>y;
		e=0;
		int f=0,g=0;
		e+=w[x];
		for(int j=0;j<n;j++){
			for(int k=1;k<=a[j][0];k++){
				if(a[j][k]==x) f=k;
				else if(a[j][k]==y) g=k;
			}
			if()
		}
	}
	return 0;
} 
