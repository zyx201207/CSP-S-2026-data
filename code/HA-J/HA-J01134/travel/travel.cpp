#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int n,m,g,h;
	char c,d;
	cin>>n>>m>>c>>g>>h>>d;
	if(n!=g)
	    cout<<"0000";
	else if(n==g&&m!=h)
	    cout<<"1000";
	else if(n==g&&m==h&&c>='A'&&c<='C'&&d>='D'&&d<='F')
	    cout<<"1100";
	else if(n==g&&m==h&&c>='D'&&c<='F'&&d>='A'&&d<='C')
	    cout<<"1100";
	else if(n==g&&m==h&&c>='D'&&c<='F'&&d>='D'&&d<='F')
	    cout<<"1111";
	else if(n==g&&m==h&&c>='A'&&c<='C'&&d>='A'&&d<='C'&&c+1!=d&&c-1!=d)
	    cout<<"1110";
	else if(n==g&&m==h&&c>='A'&&c<='C'&&d>='A'&&d<='C'&&c+1==d)
	    cout<<"1111";
	else if(n==g&&m==h&&c>='A'&&c<='C'&&d>='A'&&d<='C'&&c-1==d)
	    cout<<"1111";
	return 0;
} 
