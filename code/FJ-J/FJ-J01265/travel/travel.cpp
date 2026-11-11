#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
int x,y;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(a[0]!=c[0]||a[1]!=c[1]){
		cout<<"0000";
		return 0;
	}
	else cout<<"1";
	if(b[0]!=d[0]||b[1]!=d[1]){
		cout<<"000";
		return 0;
	}
	else cout<<"1";
	x=b[2]-'A';
	y=d[2]-'A';
	if((x<=2&&y<=2)||(x>2&&y>2)) cout<<"1";
	else{
		cout<<"00";
		return 0;
	}
	if(abs(x-y)==1) cout<<"1";
	else cout<<"0";
	return 0;
}
