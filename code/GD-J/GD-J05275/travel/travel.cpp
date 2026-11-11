#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	int aa=0,bb=0,cc=0,dd=0;
	if(a==c)aa++;
	if(b[1]==d[1]&&b[0]==d[0])bb++;
	if(b[2]-'A'>2==d[2]-'A'>2)cc++;
	if((cc!=0)&&((b[2]-d[2])*(b[2]-d[2])==1)) dd++;
	cout<<aa<<bb<<cc<<dd;
	return 0;
}
