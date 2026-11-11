#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	if(a==c){
		cout<<1;
	}
	else{
		cout<<0;
	}
	string b1,d1;
	b1+=b[0];
	d1+=d[0];
	b1+=b[1];
	d1+=d[1];
	if(a==c&&b1==d1){
		cout<<1;
	}
	else{
		cout<<0;
	}
	char b2=b[2],d2=d[2];
	bool kk=1;
	if((a==c&&b1==d1)&&((b2=='F'&&d2=='D')||(b2=='A'&&(d2=='B'||d2=='C'))||(d2=='A'&&(b2=='B'||b2=='C'))))
	{
	kk=0;
	}	
	if(b1==d1&&kk==0){
		cout<<1;
	}
	else{
		cout<<0;
	}
	if(((a==c&&b1==d1)&&((b2=='F'&&d2=='D')||(b2=='A'&&(d2=='B'||d2=='C'))||(d2=='A'&&(b2=='B'||b2=='C'))))&&(!(b2=='D'&&d2=='C')&&((b2=='D'&&d2=='F')||(d2=='D'&&b2=='F')||(d2-b2==1)||(b2-d2==-1))))
	{
		cout<<1;
	}
	else{
		cout<<0;
	}

	return 0;
}

