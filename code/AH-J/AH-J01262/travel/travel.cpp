#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("travel.in","r",stdin);
freopen("travel.out","w",stdout);
bool f=1;
string a,b,c,d;
cin>>a>>b>>c>>d;
char q=b[2];
char p=d[2];
if(a==c) cout<<1;
else{
	cout<<0;
	f=0;
}
if(b[0]==d[0]&&b[1]==d[1]&&f==1) cout<<1;
else{
	cout<<0;
	f=0;
}
if(((q>='A'&&q<='C')&&(p>='A'&&p<='C'))||((q>='D'&&q<='F')&&(p>='D'&&p<='F'))){
	if(f==1) cout<<1;
	else cout<<0;
}else{
	cout<<0;
	f=0;
}
if(int(abs(q-p))==1&&f==1) cout<<1;
else cout<<0;
return 0;
}
	
