#include<bits/stdc++.h>
using namespace std;
long long n,ans,cnt,bj,y,num,jq;
string s,a,b,m,d;
char sc;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		long long x;
		cin>>x;
		cnt+=x;
		char c;
		cin>>c;
		if(i==1)sc = c;
		else{
			if(sc!=c)bj = 1;
			sc = c;
		}
		for(int i=1;i<=x;i++)s+=c;
	}
	if(bj==0)
	{
		cout<<"0";
		return 0;
	}
	if(cnt%2==0)
	{
		y = cnt/2;
		a = s.substr(0,y);
		b = s.substr(y);
	}
	else{
		y = cnt/2+1;
		a = s.substr(0,y-1);
		b = s.substr(y);
	}
	for(int i=0;i<b.length();i++)
	{
		d[num++] = b[b.length()-1-jq];
		jq++;
	}
	for(int i=0;i<y;i++)
	{
		if(a[i]!=d[i])ans++;
	}
	cout<<ans;
	return 0;
}
