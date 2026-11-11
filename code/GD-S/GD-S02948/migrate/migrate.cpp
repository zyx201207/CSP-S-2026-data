#include<bits/stdc++.h>
using namespace std;
long long a,b,c[2000000][2],d[2000000][2000000]={},g,h;
mm(int m,int p,int o){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	if(m == d[o][c[o][0]-1]){
		if(g<m){
			g=m;
			h=1;
		}
		if(g==m){
			h++;
		}
	}
	if(m>d[o][c[o][0]-1]){
		return 0;
	}
	p++;
	for(int i=1;i<=c[o][1];i++){
		for(int j=0;j<c[o][0];j++){
			if(m+i==d[o][j]){
				return mm(m+i,p,o);
				break;
			}
		}
	}
	return 0;
}
main(){	
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>a>>b;
	for(int i=0;i<b;i++){
		cin>>c[i][0]>>c[i][1];
		for(int j=0;j<c[i][0];j++){
			cin>>d[i][j];
		}
	}
	for(int i=0;i<b;i++){
		g=0;
		h=0;
		mm(d[i][0],0,i);
		cout<<h;
	}
	return 0;
} 
