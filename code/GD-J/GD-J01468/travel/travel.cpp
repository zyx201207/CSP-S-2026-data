#include<bits/stdc++.h>
using namespace std;
char x,y;
map<string,int>p;
string a,c,b,d,e,f,z;
int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	p["AB"]=p["BC"]=p["DF"]=1;
	p["AC"]=2;
	for(int i=0;i<b.size()-1;i++) e+=b[i];
	for(int i=0;i<d.size()-1;i++) f+=d[i];
	x=b[e.size()],y=d[f.size()];
	if(a!=c) cout<<"0000";
	else if(e!=f) cout<<"1000";
	else {
		z=x;
		z+=y;
		sort(z.begin(),z.end());
		if(!p[z]) cout<<"1100";
		else if(p[z]==2) cout<<"1110";
		else cout<<"1111"; 
	}
	return 0;
}
