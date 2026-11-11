#include<bits/stdc++.h>
using namespace std;
int n;
long long len, x,sum;
char m;
string s;

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
    cin >> n;
    for (int i = 1; i <= n;i++)
    {
        cin >> x >> m;
        for (long long i = 1; i <= x;i++)
        {
            s += m;
        }
        len += x;
    }
    if(len%2!=0)
    {
        string s2,s1;
        for(long long i = 0;i<=len/2-1;i++)s1+=s[i];
        for(long long i = len/2+1; i <= len-1;i++)s2 += s[i];
        for(long long i = 0; i <= len/2-1;i++)
        {
            if(s1[i]!=s2[i])sum++;
        }
    }
    else
    {
    	string s2,s1;
        for(long long i = 0;i<=len/2-1;i++)s1+=s[i];
        for(long long i = len/2; i <= len-1;i++)s2 += s[i];
        for(long long i = 0; i <= len/2-1;i++)
        {
            if(s1[i]!=s2[i])sum++;
        }
        cout<<sum;
	}
	return 0;
}
