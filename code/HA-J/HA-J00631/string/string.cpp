#include<bits/stdc++.h>
using namespace std;
long long n,k,sum,x;
long long a[200010];
char b[200010];
string ch;
long long check(string s)
{
	int q=s.size()-1,t=q;
	for(int i=0;i<=(q+1)/2;i++)
	{
		if(a[i]!=a[t]) sum++;
		t--;
	}
	return sum;
}
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	k=n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>b[i];
		while(a[i]>0) { ch=ch+b[i];a[i]--;} 
	}
	cout<<check(ch);    
return 0;
}
