#include<bits/stdc++.h>
using namespace std;
long n,x,y,z;
char a;
string s;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>x>>a;
		for(int j=1;j<=x;j++)
		{
			s+=a;
		}
	}
    y=s.size();
    for(int k=0;k<y;k++)
		{
			if(k==y/2)break;
			if(s[k]!=s[y-k-1])z+=1;	
		}
	cout<<z;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
