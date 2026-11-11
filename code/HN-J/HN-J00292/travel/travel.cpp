#include<bits/stdc++.h>
using namespace std;
int c1,c2;
bool l;
string s1,s2;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==1&&c1==16){
		cout<<0000;
		return 0;
	}
	if(c1==c2) cout<<1;
	else cout<<0,l=1;
	int a1=(s1[0]-'0')*10+s1[1]-'0',a2=(s2[0]-'0')*10+s2[1]-'0';
	if(!l&&a1==a2) cout<<1;
	else cout<<0,l=1;
	bool l1=1,l2=0;
	if(s1[2]>='A'&&s1[2]<='C') l1=1;
	else l1=0;
	if(s2[2]>='A'&&s2[2]<='C') l2=1;
	else l2=0;
	if(!l&&l1==l2) cout<<1;
	else cout<<0,l=1;
	if(l) cout<<0;
	else{
		int q1=s1[2],q2=s2[2];
		if(q1+1==q2||q2+1==q1) cout<<1;
		else cout<<0;
	}
	return 0;
}
