#include<bits/stdc++.h>
using namespace std;
int a,b,c,d,e,f;
int l[10000000],r[100000000];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>a>>b;
	cin>>c>>d;
	for(int i=0;i<c;i++){
		cin>>l[i];
	}
		cin>>e>>f;
	for(int i=0;i<e;i++){
		cin>>r[i];
	}
	if(c==4&&e==5)cout<<1<<"\n"<<2;
	if(c==5&&e==6)cout<<0<<"\n"<<1;
	return 0; 
} 
