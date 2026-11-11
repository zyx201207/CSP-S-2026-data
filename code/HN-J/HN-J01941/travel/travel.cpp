#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a,b,c,d,s=0;
	cin>>a>>b;
	char x;
	cin>>x;
	cin>>c>>d;
	char y;
	cin>>y;
	if(a==c){
		cout<<1;
	}
	else{
		cout<<0;
		s=1;
	}
	if(b==d&&s==0) cout<<1;
	else{
		cout<<0;
		s=1;
	}
	if(s==0&&((x>='D'&&x<='F'&&y>='D'&&y<='F'&&x!='E'&&y!='E')||(x>='A'&&x<='C'&&y>='A'&&y<='C'))) cout<<1;
	else cout<<0;
	if(s==0&&((x=='A'&&y=='B')||(x=='B'&&(y=='A'||y=='C'))||(x=='C'&&y=='B')||(x=='D'&&y=='F')||(x=='F'&&y=='D'))) cout<<1;
	else cout<<0;
	return 0;
}
