//GZ-J00597 六盘水市第二十四中学 王轩宇
#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long a,d,f=0;
	cin>>a;
	long long b[a+5];
	char c[a+5];
	for(int i=1;i<=a;i++)
	{
		cin>>b[i]>>c[i];
		d+=b[i];
	}
	char e[d+1];
	for(int i=1;i<=a;i++)
	{
		e[b[i]]={c[i]};
	}
	for(int i=1;i<=d;i++)
	{
		if(e[i]!=e[d-i+1])
		{
			f++;
		}
	}
	cout<<f;
	return 0;
}

