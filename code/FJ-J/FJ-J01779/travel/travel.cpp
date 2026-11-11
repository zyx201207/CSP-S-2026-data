#include <bits/stdc++.h>
using namespace std;
struct xy{
	int z,x,y;
}n,m;
string a,b,c,d;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	n.z=(a[0]-'0')*10+(a[1]-'0');
	m.z=(c[0]-'0')*10+(c[1]-'0');
	n.y=(b[0]-'0')*10+(b[1]-'0');
	m.y=(d[0]-'0')*10+(d[1]-'0');
	n.x=b[2]-'A';
	m.x=d[2]-'A';
	if (n.z==m.z){
		cout<<1;
	}
	else{
		cout<<0<<0<<0<<0;
		return 0;
	}
	if (n.y==m.y){
		cout<<1;
	}
	else{
		cout<<0;
	}
	if (n.y==m.y&&((n.x<=2&&m.x<=2)||(n.x>2&&m.x>2))){
		cout<<1;
	}
	else{
		cout<<0<<0;
		return 0;
	}
	if (abs(n.x-m.x)==1){
		cout<<1;
	}
	else{
		cout<<0;
	}
	return 0;
}
