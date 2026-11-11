#include<bits/stdc++.h>
using namespace std;
int tt,t,n,m,a[2000234],dn,s;
int tc(int x,int y,int d){
	int i=x;
	if(i>=y) return d;
	while(a[i]-a[x]<=m&&i<=n) i++;
	i--;
	return tc(i,y,d+1);
}
int fk(int x,int y,int d){
	if(d==s){
		if(x==y) return 1;
		else return 0;
	}
	int f=0;
	for(int i=x+1;i<=y&&a[i]-a[x]<=m;i++){
		f+=fk(i,y,d+1);
		if(f>2) break;
	}
	return f;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>tt>>t;
	for(int k=1;k<=t;k++){
		cin>>n>>m;
		dn=0;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				s=tc(i,j,0);
				if(fk(i,j,0)==2){
					dn++;
				}
			}
		}
		cout<<dn<<endl;
	}
	return 0;
}
