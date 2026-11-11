//GZ-J00415 兴义市弘毅中学 程峻熙 
#include<bits/stdc++.h>
using namespace std;
long long a,b;
string c,d;
bool p[4];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>a>>c>>b>>d;
	p[1]=(a==b);
	p[2]=(c[0]==d[0])&&(c[1]==d[1]);
	p[3]=(c[2]>='A'&&c[2]<='C')&&(d[2]>='A'&&d[2]<='C')||(c[2]=='D'||c[2]=='F')&&(d[2]=='D'&&d[2]=='F');
	p[4]=(c[2]-d[2]==-1)||(c[2]-d[2]==1);
	cout<<(int)p[1]<<(int)(p[1]&&p[2])<<(int)(p[1]&&p[2]&&p[3])<<(int)(p[1]&&p[2]&&p[3]&&p[4]);
	return 0;
}

