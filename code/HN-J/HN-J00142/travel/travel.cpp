#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
string p1,p2;
int d1,d2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)
	cout<<1;
	else{
	cout<<"0000";
	return 0;
	}
	for(int i=0;i<s1.size();i++){
		if(s1[i]>='0'&&s1[i]<='9')
		p1=p1+s1[i];
	}
	for(int i=0;i<s2.size();i++){
		if(s2[i]>='0'&&s2[i]<='9')
		p2=p2+s2[i];
	}
	d1=s1[s1.size()-1];
	d2=s2[s2.size()-1];
	if(p1==p2)
	cout<<1;
	else
	cout<<0;
	if(p1==p2&&((d1<='C'&&d2<='C')||(d1>='D'&&d2>='D')))
	cout<<1;
	else
	cout<<0;
	if((max(d1,d2)-min(d1,d2)==1)&&p1==p2){
		if((d1<='C'&&d2<='C')||(d1>='D'&&d2>='D'))
		cout<<1;
		else
		cout<<0;
	}
	else
		cout<<0;
	return 0;
} 
