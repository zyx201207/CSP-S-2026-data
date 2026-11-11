#include<bits/stdc++.h> 
using namespace std;
string c1,s1,c2,s2;
char a[10],b[10];
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)cout<<1;
	else{
		cout<<0<<0<<0<<0;
		return 0;
	}
	for(int i=0;i<s1.size();i++){
		a[i+1]=s1[i];
		b[i+1]=s2[i];
	}
	if(a[1]==b[1]&&a[2]==b[2])cout<<1;
	else{
		cout<<0<<0<<0;
		return 0;
	}
	if((a[3]<='C'&&b[3]<='C')||(a[3]>'C'&&b[3]>'C'))cout<<1;
	else{
		cout<<0<<0;
		return 0;
	}
	int x=int(a[3]);
	int y=int(b[3]);
	if(abs(x-y)==1)cout<<1;
	else{
		cout<<0;
		return 0;
	}
	return 0;
}
