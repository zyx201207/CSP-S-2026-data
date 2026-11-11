#include<bits/stdc++.h>
using namespace std;
long long n,a,b=0,d=0,e=0;
char c;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a>>c;
		d+=a;
		while(a!=0)
		{
			s[b]=c;
			b++;
			a--;
		}
	}
	for(int i=0;i<=d-1;i++)
	{
		if(s[i]!=s[d-1-i])
		{
			s[d-1-i]=s[i];
			e++;
		}
	}
	cout<<e;
	return 0;
} 
