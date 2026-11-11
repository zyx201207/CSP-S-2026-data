#include<bits/stdc++.h>
using namespace std;
vector<long long>v(1000000010);
string s;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
    int n,m;
    for(int i=1;i<=n;i++)
    {
    	cin>>v[i]>>s;
    	m+=v[i];
	}
    for(int i=1;i<=n;i++)
    {
    if(s[m%2+i]!=s[m%2-i])
	{
	cout<<m-(m-i);
	return 0;
	
    }	
	}
	return 0;
}