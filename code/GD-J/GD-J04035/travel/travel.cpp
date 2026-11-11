#include<bits/stdc++.h> 
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,c2;
	string s1,s2;
	cin>>c1>>s1>>c2>>s2;
	cout<<(c1==c2);
	int q1,q2;
	char p1,p2;
	q1=(s1[0]-'0')*10+(s1[1]-'0');
	q2=(s2[0]-'0')*10+(s2[1]-'0');
	p1=s1[2],p2=s2[2];
	if(q1==q2){
		cout<<1;
		int a;
		if(p1>='A'&&p1<='C'&&p2>='A'&&p2<='C'){
			a=1;
		}
		else if(p1>='D'&&p1<='E'&&p2>='D'&&p2<='E'){
			a=1;
		}
		else{
			a=0;
		}
		cout<<a;
		if(a==1&&abs(p1-p2)<=1) cout<<1;
		else cout<<0;
	}
	else{
		cout<<0;
		cout<<0;
		cout<<0;
	}
	return 0;
}
