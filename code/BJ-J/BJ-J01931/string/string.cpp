#include<bits/stdc++.h>
using namespace std;
long long a[200005];
char b[200005];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    int cur=0;
    long long all=0;
    for(int i=1;i<=n;i++)
    {
        cur++;
        long long m;
        char x;
        cin>>m>>x;
        if(all<=1e9)all+=m;
        if(b[cur-1]==x)
        {
            cur--;
            a[cur]+=m;
        }
        else{
            a[cur]=m;
            b[cur]=x;
        }
    }
    if(all/2<=1e6)
    {
        long long ans=0;
        string s="";
        for(int i=1;i<=cur;i++)
        {
            for(int j=1;j<=a[i];j++)
            {
                s+=b[i];
            }
        }
        for(int i=0;i<s.size()/2;i++)
        {
            if(s[i]!=s[s.size()-i+1])ans++;
        }
        cout<<ans;
        return 0;
    }
    long long ans=0;
    for(int i=1;i<=cur/2;i++)
    {
        //cout<<"#";
        if(b[i]==b[cur-i+1])
        {
            ans+=abs(a[i]-a[cur-i+1]);
            //cout<<"#";
        }
        else
        {
            if(a[i]<a[cur-i+1])
            {
                a[i+1]-=(a[cur-i+1]-a[i]);
                ans+=a[cur-i+1];
                //cout<<"#1";
            }
            else if(a[i]>a[cur-i+1])
            {
                a[cur-i]-=(a[i]-a[cur-i+1]);
                ans+=a[i];
                //cout<<"#2";
            }
            else{
                ans+=a[i];
                //cout<<"#3";
            }
        }
    }
    cout<<ans;
    return 0;
}
