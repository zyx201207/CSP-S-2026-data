#include<bits/stdc++.h>
using namespace std;
int na,ma;
string nb,mb;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>na>>nb>>ma>>mb;
	cout<<(na==ma);
	cout<<(na==ma&&nb[0]==mb[0]&&nb[1]==mb[1]);
	cout<<(na==ma&&nb[0]==mb[0]&&nb[1]==mb[1]&&(((nb[2]<='C')&&(mb[2]<='C'))||((nb[2]>'C')&&(mb[2]>'C'))));
	cout<<(na==ma&&nb[0]==mb[0]&&nb[1]==mb[1]&&(((nb[2]<='C')&&(mb[2]<='C'))||((nb[2]>'C')&&(mb[2]>'C')))&&abs(nb[2]-mb[2])==1);
	return 0;
}
