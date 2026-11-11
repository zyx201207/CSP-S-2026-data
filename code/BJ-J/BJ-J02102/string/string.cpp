#include<bits/stdc++.h>
using namespace std;
string s;
char a;
long long n,m,len,ans;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(long long i=1;i<=n;i++)
    {
        cin>>m>>a;
        len+=m;
        for(long long j=len-m+1;j<=len;j++)s[i]=a;
    }
    for(long long i=1;i<=(len/2);i++)
    {
        if(s[i]!=s[len-i+1])ans++;
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
