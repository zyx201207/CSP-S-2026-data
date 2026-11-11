#include<bits/stdc++.h> 
#define ll long long
using namespace std;
string c1,s1,c2,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ll a,b;
	char c,d;
	bool s=false;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<"1";	
		s=true;
	}
	else cout<<"0";
	a=s1[0]*10+s1[1];
	b=s2[0]*10+s2[1];
	if(s&&a==b)cout<<"1";
	else{
		cout<<"0";
		s=false;
	}
	c=s1[2];
	d=s2[2];
	if(s&&(((c=='A'||c=='B'||c=='C')&&(d=='A'||d=='B'||d=='C'))||((c=='D'||c=='F')&&(d=='D'||d=='F')))){
		cout<<"1";
	}
	else{
		cout<<"0";
		s=false;
	}
	if(s&&((c=='A'&&d=='B')||(c=='B'&&d=='C')||(c=='D'&&d=='F')))cout<<"1";
	else cout<<"0";
	return 0;
}

