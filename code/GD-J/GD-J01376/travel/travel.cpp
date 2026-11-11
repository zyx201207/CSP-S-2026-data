#include<bits/stdc++.h>
#define int long long
using namespace std;
string c1,s1,c2,s2;
main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
	}
	else{
		cout<<"0000";
		return 0;
	}
	
	int pai1=(s1[0]-'0')*10+s1[1]-'0',pai2=(s2[0]-'0')*10+s2[1]-'0';
	if(pai1==pai2){
		cout<<1;
	}
	else{
		cout<<"000";
		return 0;
	}
	
	char a=s1[2],b=s2[2];
	if((a>='A' && a<='C' && b>='A' && b<='C') || (a<='F' && a>='D' && b<='F' && b>='D')){
		cout<<1;
	}
	else{
		cout<<"00";
		return 0;
	}
	
	if((a=='A' && b=='B') || (a=='B' && b=='A') || (a=='B' && b=='C') || (a=='C' && b=='B') || (a=='D' && b=='F') || (a=='F' && b=='D')){
		cout<<1;
	}
	else{
		cout<<0;
	}
	
	return 0;
}
