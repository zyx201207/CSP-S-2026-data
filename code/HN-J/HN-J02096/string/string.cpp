#include<bits/stdc++.h>
using namespace std;
string s=" ",c;
long long m,n,p,cnt;
int main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>m;
	while(m--)
	{
		cin>>p>>c;
		n+=p;
		for(int i=1;i<=p;i++) s+=c;
	}
	if(n%2==1) n--;
	for(int i=1;i<=n/2;i++) if(s[i]!=s[n-i+1]) cnt++;
	cout<<cnt;
	return 0;
}
