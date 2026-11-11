#include<bits/stdc++.h>
using namespace std;
int a1,b1,a2,b2;
char c1,c2;
bool a=false,s=false,d=false;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d %d%c %d %d%c",&a1,&b1,&c1,&a2,&b2,&c2);
	if(a1==a2){cout<<1;a=true;}else{cout<<0;}
	if(b1==b2&&a){cout<<1;s=true;}else{cout<<0;}
	if((a&&s)&&((c1=='F'&&c2=='D')||(c1=='D'&&c2=='F')||(c1=='A'&&c2=='B')||(c1=='A'&&c2=='C')||(c1=='B'&&c2=='C')||(c1=='B'&&c2=='A')||(c1=='C'&&c2=='A')||(c1=='C'&&c2=='B'))){cout<<1;d=true;}else cout<<0;
	if(a&&s&&d&&((c1!='A'&&c2!='c')&&(c1!='C'&&c2!='A')))cout<<1;else cout<<0;
	return 0;
}

