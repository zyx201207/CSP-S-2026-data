#include <bits/stdc++.h>
//rp hao xiang yi chu le
using namespace std;
int n;
long long sum;
string s;
inline int read()
{
	int x=0,f=1;char ch=getchar_unlocked();
	while(ch<'0'||ch>'9') {if(ch=='-') f=-1;ch=getchar_unlocked();}
	while(ch>='0'&&ch<='9') x=x*10+ch-48,ch=getchar_unlocked();
	return x*f;
}
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
    n=read();
    while(n--)
    {
		int a=read();
		char ch=getchar_unlocked();
		while(a--) s+=ch;
	}
	for(long long l=0,r=s.size()-1;l<r;l++,r--)
	{
		if(s[l]!=s[r]) sum++;
	}
	cout<<sum;
	return 0;
}
