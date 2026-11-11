#include <bits/stdc++.h>
using namespace std;
int a[100010];
char ch[100010];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    scanf("%d",&n);
    long long sum=0;
    string s="";
    for(int i=1;i <= n;i++)
    {
        cin >> a[i] >> ch[i];
        for(int j=1;j <= a[i];j++)
        {
            s+=ch[i];
        }
    }
    int m=s.size();
    long long cnt=0;
    for(int i=0;i < m/2;i++)
    {
        if(s[i]!=s[m-1-i])
        {
            cnt++;
        }
    }
    printf("%lld",cnt);
    return 0;
}

