#include <bits/stdc++.h>
using namespace std;
int n;
const int N=2e5+5;
int a[N];
char c;
int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    string s="";
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>c;
        for(int j=1;j<=a[i];j++)
        {
            s+=c;
        }
    }
    int l=s.size();
    bool flag=1;
    for(int i=0;i<l;i++)
    {
        if(s[i]!=s[l-1-i]) flag=0;
    }
    if(flag==1){
        cout<<0<<endl;
        return 0;
    }
    int res=0;
    for(int i=0;i<l;i++)
    {
        if(s[i]!=s[l-1-i])
        {
            s[l-1-i]=s[i];
            res++;
        }
    }
    cout<<res<<endl;
    return 0;
}
