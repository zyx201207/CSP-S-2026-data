#include<bits/stdc++.h>
using namespace std;
int n,a;
char s;
string book;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a>>s;
		for(int j=1;j<=a;j++) book+=s;
	}
	long long ans=0,l=0,r=0;
	if(book.size()%2==0) l=book.size()/2-1,r=l+1;
	else l=r=book.size()/2;
	long long len=book.size();
	while(l>=0&&r<len)
	{
		if(book[l]!=book[r]) ans++;
		l--,r++;
	}
	cout<<ans;
	return 0;
}
