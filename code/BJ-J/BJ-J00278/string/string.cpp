#include<bits/stdc++.h>
using namespace std;
long long a[200020];
char c[200020];
string s;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]; //2 2 1
        cin>>c[i]; //a b c
    }
    long long temp=1;
    long long cnt=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=a[i];j++)
        {
            s[temp]=c[i];
            temp++;
        }
    }
    for(long long i=1;i<=temp/2;i++)
    {
        if(s[i]!=s[temp-i]) cnt++;
    }
    cout<<cnt;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
