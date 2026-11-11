#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	int n,a,i,j,m,q=0,w;
	char c;
	string s;
	
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		cin>>a>>c;
		for(j=1;j<=a;j++)
			s += c;
	}
	for(i=0;i>=s.size()-1;i++)
		if(s[i] != s[s.size()-1-i])
			q++;
	cout<<q;
		
	return 0;
}

