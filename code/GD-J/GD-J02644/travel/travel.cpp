#include<bits/stdc++.h>
using namespace std;
int _abs(int a){
	return a<0?-a:a;
}
int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0); 
	int c1,c2;
	string s1,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2) {
		cout<<"0000";
		return 0;
	}
	int a1=(s1[0]-'0')*10+s1[1]*-'0',
		a2=(s2[0]-'0')*10+s2[1]*-'0';
	cout<<"1"
		<<(a1==a2?1:0);
	if(a1==a2){
		if((s1[2]>='D')&&(s2[2]>='D'))
			cout<<"1";
		else if(s1[2]<='C'&&s2[2]<='C')
			cout<<'1';
		else cout<<"0";
	}
	else cout<<"0";
	if(((s1[2]==s2[2])&&(_abs(a1-a2)))==1 || 
		(((a1==a2)&&_abs(s1[2]-s2[2]))==1)&&!((s1[2]=='C'&&s2[2]=='D')||(s2[2]=='C'&&s1[2]=='D')))
		cout<<1;
	else 
		cout<<0;
	return 0;
}
