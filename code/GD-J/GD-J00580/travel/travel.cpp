#include<bits/stdc++.h>
using namespace std;
int c1,c2;
string s1,s2;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
		cout<<"0000"<<'\n';
		return 0;	
	}
	int p1,p2;
	p1=s1[0]-'0'*10+s1[1]-'0';
	p2=s2[0]-'0'*10+s2[1]-'0';
	char z1=s1[2],z2=s2[2];
	if(p1==p2)
	{
		if((z1=='A'&&z2=='B')||(z1=='A'&&z2=='C')||(z1=='B'&&z2=='A')||(z1=='B'&&z2=='C')||(z1=='C'&&z2=='A')||(z1=='C'&&z2=='B')||(z1=='D'&&z2=='F')||(z1=='F'&&z2=='D'))
		{
			cout<<"111";
			if(abs(z1-z2)==1)
				cout<<"1"<<'\n';
			else
				cout<<"0"<<'\n';
			return 0;
		}
		else{
			cout<<"1100"<<'\n';
			return 0;
		}
	}
	cout<<"1000"<<'\n';
	return 0;
}
