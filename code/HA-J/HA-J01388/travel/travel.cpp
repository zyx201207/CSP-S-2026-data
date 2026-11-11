#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	char a,b,c,d,e,f,g,h,i,j;
	cin>>a>>b>>c>>d>>e>>f>>g>>h>>i>>j;
	if(a==f&&b==g){
		cout<<1;
	}
	else cout<<0;
	if(c==h&&d==i&&a==f&&b==g){
		cout<<1;
	}
	else cout<<0;
	if(c==h&&d==i&&a==f&&b==g&&c==h&&d==i&&((e=='A'&&j=='B')||(e=='A'&&j=='C')||(e=='B'&&j=='A')||(e=='B'&&j=='C')||(e=='C'&&j=='A')||(e=='C'&&j=='B')||(e=='D'&&j=='F')||(e=='F'&&j=='D'))){
		cout<<1;		
	}else cout<<0;
	if(c==h&&d==i&&a==f&&b==g&&((e=='A'&&j=='B')||(e=='B'&&j=='C')||(e=='C'&&j=='B')||(e=='B'&&j=='A')||(e=='D'&&j=='F')||(e=='F'&&j=='D'))){
		cout<<1;
	}else cout<<0;
	return 0;
}

