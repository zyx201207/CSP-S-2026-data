#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int t;
    scanf("%d",&t);
    string s;
    while(t--)
    {
        int n;
        char c;
        scanf("%d",&n);
        cin>>c;
        for(int i=1;i<=n;i++) s+=c;
    }
    string a=s;
    reverse(s.begin(),s.end());
    long long ans=0;
    for(long long i=0;i<s.size()/2;i++) if(a[i]!=s[i]) ans++;
    cout<<ans;
    return 0;
}
