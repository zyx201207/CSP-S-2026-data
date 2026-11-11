#include<bits/stdc++.h>
#define f(i,e,s) for(int i=e;i<=s;i++)
using namespace std;
typedef long long ll;
const ll N=1e5+10,G=5e2+8,inf=0x3f3f3f3f3f3f3f3f;
ll get(char c)
{
	if(c=='F') return 5;
	return c-'A'+1;
}
string s;
ll a[N];
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	getline(cin,s);
	ll cnt=1;
	int len=s.size();
//	cout<<len<<endl;
	for(int i=0;i<len;i++)
	{
//		if(!((s[i]>='0' && s[i]<='9') || (s[i]>='A' && s[i]<='F'))) cnt++;
		if(s[i]==' ')
		{
			cnt++;
//			cout<<i<<" ";
			continue;
		}
		if(s[i]>='0' && s[i]<='9') (a[cnt]*=10)+=(s[i]-'0');
		if(s[i]>='A' && s[i]<='F') a[++cnt]=get(s[i]);
	}
//	f(i,1,6) cout<<a[i]<<" ";
	bool f0=0,f1=0,f2=0;
	if(a[1]==a[4])
	{
		cout<<1;
		f0=1;
	}
	else cout<<0;
	if(f0 && a[2]==a[5])
	{
		f1=1;
		cout<<1;
	}
	else cout<<0;
	if(f1 && ((a[3]>=1 && a[6]<=3) || (a[3]>=4 && a[6]<=6)))
	{
		cout<<1;
		f2=1;
	}
	else cout<<0;
	if(f2 && ((a[3]+1==a[6]) || (a[3]-1==a[6]))) cout<<1;
	else cout<<0;
	return 0;
}













































