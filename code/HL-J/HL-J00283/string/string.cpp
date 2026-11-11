#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("string.in ","r",stdin);
    freopen("string.out","w",stdout);
    int n,m;
    string s="";
    char a;
    cin>>n;
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        cin>>m>>a;
        for(int j=0;j<m;j++)
            s+=a;
    }
    long long p=s.length();
    long long j=p-1;
    for(int i=0;i<p;i++)
    {
            if(s[i]!=s[j])
            {
                ans++;
            }
            j--;
    }
    cout<<ans/2;
    return 0;
}
