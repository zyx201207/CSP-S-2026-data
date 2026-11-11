//GZ-J00252 贵阳市第十七中学 吴芸智
#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,t=0;
	cin>>n;
	string s;
	int len=0;
	for(int i=1;i<=n;i++)
	{
		int x;
		char y;
		cin>>x>>y;
		for(int i=1;i<=x;i++){
		    s[len+i]+=y;
	    }
		len+=x;
	}
	for(int i=1,j=len;i<len/2,j>len/2;i++,j--)
	{
		if(s[i]!=s[j]) 	t++;
	}
	cout<<t;
	return 0;
}
