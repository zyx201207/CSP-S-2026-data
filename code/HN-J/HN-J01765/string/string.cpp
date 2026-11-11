#include<bits/stdc++.h>
using namespace std;
int n,a,r=0,l,f1=0,b;
string s;
char c;   
void f2()
{
	for(int j=1;j<=a;j++)
		{
			s+=c;
		}
		return;
}
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;                                         
	for(int i=1;i<=n;i++)
	{
		cin >> a >> c;
		f2();
	}
	l=s.size()-1;
	b=l/2;
	while(b--)
	{
		if(s[r]!=s[l]) f1++;
		r++;
		l--;
	}
	cout << f1 << endl;
	return 0;
}
