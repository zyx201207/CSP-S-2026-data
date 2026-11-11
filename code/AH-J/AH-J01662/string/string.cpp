//AH-J01662 LSJ Liu Shijie
#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
long long n,sum;
int nu[N],t;
char c;
string s,l,r;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>nu[i]>>c;
		string t(nu[i],c);
		s+=t;
	}
	l=s.substr(0,(s.size()+1)/2);
	r=s.substr(s.size()/2,(s.size()+1)/2);
	reverse(r.begin(),r.end());
	for(int i=0;i<l.size();i++)
	{
		if(l[i]!=r[i])
		{
			sum++;
		}
	}
	cout<<sum;
	return 0;
}
// Trick||Treat!
