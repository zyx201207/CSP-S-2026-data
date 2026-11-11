#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a1=0,a2=0,a3=0,a4=0;
	int b1=0,b2=0;
	int c1,c2;
	string s1,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1!=1&&c1!=16&&c2!=1&&c2!=16){
		if(c1==c2)
		{
			a1=1;
		 } 
		b1=s1[0]*10+s1[1]; 
		b2=s2[0]*10+s2[1];
		if(b1==b2&&a1==1)
		{
			a2=1;
		}
		if(a1==1&&a2==1&&((s1[2]-'D'<0&&s2[2]-'D'<0)||(s1[2]-'D'>=0&&s2[2]-'D'>=0)))
		{
			a3=1;
		}
		if(a3==1&&a2==1&&a1==1&&(s1[2]-s2[2]==1||s1[2]-s2[2]==-1))
		{
			a4=1; 
		}
		cout<<a1<<a2<<a3<<a4;
	} 
	
	return 0;	
} 
