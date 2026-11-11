#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c2,s2;int c1,s1;cin>>c1>>c2>>s1>>s2;
	int a=c2[0]*10+c2[1],b=s2[0]*10+s2[1];
	char x=c2[2],y=s2[2];
	if(c1==s1){cout<<1;
	if(a==b){cout<<1;
	if((x=='A'&&y=='B')||(x=='B'&&y=='A')) cout<<11;
	else if((x=='A'&&y=='C')||(x=='C'&&y=='A')) cout<<10;
	else if((x=='C'&&y=='B')||(x=='C'&&y=='A')) cout<<11;
	else if((x=='D'&&y=='F')||(x=='F'&&y=='D')) cout<<11;
	else cout<<"00";
	}else cout<<"000";
	}else cout<<"0000";
	cout<<"\n";
	return 0; 
}
