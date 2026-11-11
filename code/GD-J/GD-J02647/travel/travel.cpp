#include<iostream>
using namespace std;
string a,b,c,d;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(a==c)cout<<1;
	else cout<<0;
	if(b[0]==d[0]&&b[1]==d[1]&&(a==c))cout<<1;
	else cout<<0;
	if(((b[2]-'A'<3&&d[2]-'A'<3)||(b[2]-'A'>=3&&d[2]-'A'>=3))&&(b[0]==d[0]&&b[1]==d[1]&&(a==c)))cout<<1;
	else cout<<0;
	if(abs((b[2]-'A')-(d[2]-'A'))==1&&(((b[2]-'A'<3&&d[2]-'A'<3)||(b[2]-'A'>=3&&d[2]-'A'>=3))&&(b[0]==d[0]&&b[1]==d[1]&&(a==c))))cout<<1;
	else cout<<0;
}
