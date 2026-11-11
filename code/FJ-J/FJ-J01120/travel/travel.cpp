#include<iostream>
using namespace std;
string a,b,c,d;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if (a!=c) cout<<"0000";
	else{
		if (b[0]!=d[0] || b[1]!=d[1]) cout<<"1000";
		else{
			if (b[2]+d[2]=='A'+'B' || b[2]+d[2]=='B'+'C' || b[2]+d[2]=='D'+'F') cout<<"1111";
			else if (b[2]+d[2]=='A'+'C') cout<<"1110";
			else cout<<"1100";
		} 
	}
	return 0;
}
// rp++;
