#include<bits/stdc++.h>
using namespace std;
#define int long long
string c1,c2,s1,s2;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)
		cout<<1;
	else{
		cout<<0;
		cout<<0;
		cout<<0;
		cout<<0;
		return 0;
	}
	if(s1[0]==s2[0]&&s1[1]==s2[1])
		cout<<1;
	else
		cout<<0;
	char c1=s1[2],c2=s2[2];
	if((c1<='C'&&c2<='C')||(c1>='D'&&c2>='D'))
		cout<<1;
	else
		cout<<0;
	if((c1>='D'&&c2>='D')||(c1<='B'&&c2<='B')||(c1>='B'&&c2>='B'&&c1<='C'&&c2<='C'))
		cout<<1;
	else 
		cout<<0;
	return 0;
}
