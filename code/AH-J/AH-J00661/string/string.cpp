#include<bits/stdc++.h>
using namespace std;
int n,a,ans;
char c;
string s=" ";
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a>>c;
		for(int j=1;j<=a;j++)
			s+=c;
	}
	int len=s.size()-1;
	for(int i=1;i<=ceil(len*1.0/2);i++)
		if(s[i]!=s[len+1-i]) ans++;
	cout<<ans<<endl;
	return 0;
}
