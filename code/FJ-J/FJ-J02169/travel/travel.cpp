#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e6+10;
string t1,s1,t2,s2;
struct travel{
	int cx,p,b;
}a,b; 
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>t1>>s1>>t2>>s2;
	a.cx=(t1[0]-'0')*10+t1[1]-'0';
	a.p=(s1[0]-'0')*10+s1[1]-'0';
	a.b=s1[2]-'A'+1;
	b.cx=(t2[0]-'0')*10+t2[1]-'0';
	b.p=(s2[0]-'0')*10+s2[1]-'0';
	b.b=s2[2]-'A'+1;
	if(a.cx==b.cx)cout<<1;
	else{
		cout<<0<<0<<0<<0;
		return 0;
	}
	if(a.p==b.p)cout<<1;
	else{
		cout<<0<<0<<0;
		return 0;
	}
	if((a.b<=3&&b.b<=3)||(a.b>3&&b.b>3))cout<<1;
	else{
		cout<<0<<0;
		return 0;
	}
	if((a.b+1==b.b)||(a.b-1==b.b))cout<<1;
	else{
		cout<<0;
		return 0;
	}
	return 0;
}
