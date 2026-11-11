#include<bits/stdc++.h>
using namespace std;
int n[6];
string a,b,aa,bb;
int main(){
	freopen("travel.in","w",stdin);
	freopen("travel.out","r",stdout);
	cin>>a>>aa>>b>>bb;
	if(a==b)
	{
		n[1]=1;
		if(aa[0]==bb[0]&&aa[1]==bb[1])
		{
			n[2]=1;
			if(aa[2]=='A'||aa[2]=='B'||aa[2]=='C')
			{
				if(bb[2]=='A'||bb[2]=='B'||bb[2]=='C')
				{
					n[3]=1;
					if(aa[2]-1==bb[2]||aa[2]+1==bb[2])
					{
						n[4]=1;
					}
				}
			}
			if(aa[2]=='D'||aa[2]=='E')
			{
				if(bb[2]=='D'||bb[2]=='E')
				{
					n[3]=1;
					if(aa[2]-1==bb[2]||aa[2]+1==bb[2])
					{
						n[4]=1;
					}
				}
			}
		}
	}
	for(int i=1;i<=4;i++)
	{
		cout<<n[i];
	}
	return 0;
} 
