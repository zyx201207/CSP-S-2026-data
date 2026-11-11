#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	if(a==c)cout<<1;
	else return cout<<"0000",0;
	if(b[0]==d[0] and b[1]==d[1])cout<<1;
	else return cout<<"000",0;
	if(b[2]<='C' and d[2]<='C')cout<<1;
	else if(b[2]>'C' and d[2]>'C')cout<<1;
	else return cout<<"00",0;
	int ans=b[2]-'A';
	int num=d[2]-'A';
	if(ans<num)swap(ans,num);
	if(ans-num==1 and ans!=3 and num!=2)cout<<1;
	else cout<<0;
	return 0;
}
