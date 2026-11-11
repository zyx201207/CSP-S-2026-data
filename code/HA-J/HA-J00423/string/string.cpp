#include <bits/stdc++.h>
using namespace std;
int n,a[200005];
char c[200005];
string s;
long long cnt;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	if(n==1){
		cout <<0;
		return 0;
	}
	for(int i =1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
		for(int j =0;j< a[i];j++)
		{
			s+=c[i];
		}
	}
	for(int i =0;i*2<s.size();i++)
	{
		if(s[i]!=s[s.size()-i-1])
		{
			cnt++;
		}
	}
    cout <<cnt;
    return 0;
}
