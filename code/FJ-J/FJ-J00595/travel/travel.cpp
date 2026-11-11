#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
long long sum=1,sum1=1;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	for(int i=0;i<c1.size();i++)
		if(c1[i]>='0' && c1[i]<='9')sum=sum*10+(c1[i]-'0');
	for(int i=0;i<c2.size();i++)
		if(c2[i]>='0' && c2[i]<='9')sum1=sum1*10+(c2[i]-'0');
	if(sum==sum1){
		cout<<1;	
		sum=1,sum1=1;
		for(int i=0;i<s1.size();i++)
			if(s1[i]>='0' && s1[i]<='9')sum=sum*10+(s1[i]-'0');
		for(int i=0;i<c2.size();i++)
			if(s2[i]>='0' && s2[i]<='9')sum1=sum1*10+(s2[i]-'0');
		if(sum==sum1){
			cout<<1;
			if((s1[2]=='A' || s1[2]=='B' ||s1[2]=='C') && (s2[2]=='A' || s2[2]=='B' ||s2[2]=='C') )
			{
				cout<<1;
				if(abs(s1[2]-s2[2])==1)cout<<1;
				else cout<<0;
			}
			else if((s1[2]=='D' || s1[2]=='F' ) && (s2[2]=='D' || s2[2]=='F'))
			{
				cout<<1;
				if(abs(s1[2]-s2[2])==2)cout<<1;
				else cout<<0;
			}
			else cout<<0<<0;
		}
		else cout<<0<<0<<0;
	}
	else {
		cout<<0<<0<<0<<0;
	}
	return 0;
}
