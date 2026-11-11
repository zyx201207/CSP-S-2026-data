#include<bits/stdc++.h>
using namespace std;
string s1,c1,s2,c2,b1,b2;
char a1,a2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)
	{
		cout<<1;
		a1=s1[2],a2=s2[2];
		b1=b1+s1[0]+s1[1],b2=b2+s2[0]+s2[1];
//		cout<<a1<<" "<<b1<<" "<<a2<<" "<<b2;
		if(b1==b2)
		{
			cout<<1;
			int a1s=a1-'A',a2s=a2-'A';
//			cout<<"as:"<<a1s<<" "<<a2s<<endl;
			bool flag=false,fl=true;
			int maxx=max(a1s,a2s);
			if(maxx<=2)
			{
				if(abs(a1s-a2s)<=2)flag=true;
			}	
			else if(maxx>2)
			{
				if(abs(a1s-a2s)==2&&min(a1s,a2s)!=2)flag=true;	
			}	
			if(flag)
			{
				cout<<1;
				if(abs(a1s-a2s)==1)cout<<1;
				else cout<<"0";
			}
			else cout<<"00";
		}
		else cout<<"000";
	}
	else cout<<"0000";
	
	return 0;
}
