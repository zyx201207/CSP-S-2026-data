#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,x,mid,cnt=0;
    cin>>n;
    string s;
    while(n--)
    {
    	string y;
    	cin>>x>>y;
    	for(int i=1;i<=x;i++) s+=y;
	}
	int t=s.size();
	for(int i=0,j=t-1;i<t/2;i++,j--)
	{
		if(s[i]!=s[j]) cnt++;
	}
	cout<<cnt;
    return 0;
}

