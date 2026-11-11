#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,x;
    cin>>n;
    char s;
    string str=" ";
    for(int i=1;i<=n;i++)
    {
        cin>>x>>s;
        for(int j=1;j<=x;j++)
        {
            str+=s;
        }
    }
    int leng=str.length(),sum=0;
    for(int i=1;i<=leng;i++)
    {
        if(str[i]!=str[n-i+1]) sum++;
    }
    if(sum%2==0) cout<<sum/2;
    else cout<<sum/2+1;
    return 0;
}
