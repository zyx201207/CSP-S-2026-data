#include <bits/stdc++.h>
using namespace std;
int l=1,tmpl,n;
char tmps,s[6000002];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>tmpl>>tmps;
        while(tmpl--)
        {
            s[l++]=tmps;
        }
    }
    int L=1,r=l-1,num=0;
    while(L<=r)
    {
        if(s[L++]!=s[r--])
        {
            num++;
        }
    }
    cout<<num;
	return 0;
}
