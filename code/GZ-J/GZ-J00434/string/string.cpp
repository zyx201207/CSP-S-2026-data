//GZ-J00434 雷信洋 贵阳市第三十四中学 
#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,x,s=0;
	char y;
	cin>>n;
	cin>>x>>y;
	for(int i=1;i<n;i++)
	{
		int t=x;
		char c=y;
		cin>>x>>y;
		if(y!=c&&x>t)
		{
			s=x;
		}
	}
	cout<<s;
	return 0;
}
