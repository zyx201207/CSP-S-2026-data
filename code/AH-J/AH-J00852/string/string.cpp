#include<bits/stdc++.h>
using namespace std;
int a[100000010];
int main()
{
	ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n,s=0,ss=0;
    cin>>n;
    int j=1;
    bool ch=false;
    for(int i=1;i<=n;i++)
    {
		long long x;
		char q;
		cin>>x>>q;
		s+=x;
		if(x>=100||ch)
		{
			ch=true;
			continue;
		}
		while(x--)a[j++]=q-'a'+1;
	}
	if(ch)
	{
		cout<<s/2;
		return 0;
	}
	for(int i=1,j=s;i<=j;i++,j--)
	{
		if(a[i]!=a[j])ss++;
	}
    cout<<ss;
    return 0;
}
