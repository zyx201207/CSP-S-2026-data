#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s1,s2,c1,c2;
	cin>>c1>>s1>>c2>>s2;
	bool in_same=1;
	
	if(c1==c2)cout<<1;
	else{
		cout<<"0000";
		return 0;
	}
	
	bool in_next=0;
	int k1=(s1[0]-'0')*10+s1[1]-'0',k2=(s2[0]-'0')*10+s2[1]-'0';
    if(k1==k2)cout<<1;
    else
    {
    	cout<<0;
    	in_same=0;
    	in_next=1;
	}
	
    char a1=s1[2],a2=s2[2];bool ok=0,ok2=0;
    if(a1=='A'||a1=='B'||a1=='C')ok=1;
    if(a2=='A'||a2=='B'||a2=='C')ok2=1;
    if(ok==ok2&&in_next==0)cout<<1;
    else{
    	cout<<0;
    	in_same=0;
	}
	
	bool in_near=0;
	if((a1=='D'&&a2=='F')||(a1=='F'&&a2=='D'))in_near=1;
	if((a1=='A'&&a2=='B')||(a1=='B'&&a2=='A'))in_near=1;
	if((a1=='B'&&a2=='C')||(a1=='C'&&a2=='B'))in_near=1;
	if(in_same==1&&in_near==1)cout<<1;
	else
	cout<<0;
}
