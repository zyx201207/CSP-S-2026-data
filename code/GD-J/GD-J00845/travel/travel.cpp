#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	int x = (a==c);
	int z = x&(b[0]==d[0] and b[1]==d[1]);
	int u = (z&!(max(b[2],d[2])>='D' and min(b[2],d[2])<='C'));
	int v = u&(abs(b[2]-d[2])==1);
	cout<<x<<z<<u<<v;
	return 0;
}
