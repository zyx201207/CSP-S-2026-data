#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int long long n,a,ans=0;
    cin>>n;
    string s,ss="";
    for(int i=1;i<=n;i++)
    {
        cin>>a>>s;
        for(int j=1;j<=a;j++)
            ss+=s;
    }
    int l=0,r=ss.size()-1;
    while(l!=r)
    {
        if(ss[l]!=ss[r])
            ans++;
        l++;
        r--;
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
