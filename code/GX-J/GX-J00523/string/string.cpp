#include<bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("string.in","r",stdin);
    //freopen("string.out","w",stdout);
    long long n;
    cin>>n;
    string a[1000];
    int ans=0;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        if(a[i]!=a[n-i])
        {
            ans++;
        }
        cout<<ans;
    }
    return 0;
}
