#include<bits/stdc++.h>
using namespace std;
int n,m,c=1,ma=-1;
int a[200000];
int f(int x,int y)
{
    int ans=0;
    string s,s1;
        while(x)
    {
        s+=char(x%2+'0');
        x/=2;
    }
    while(y)
    {
        s1+=char(y%2+'0');
        y/=2;
    }
    int l=s.size();
    int l1=s1.size();
    int l2=max(l,l1);
    for(int i=l2-1;i>=0;i--)
    {
        if(s[i]==s1[i]&&s[i]=='1')
        {
            ans+=(i+1)*pow(2,l2-i-1);
        }
    }
    return ans;
}
int main()
{
    //freopen("travle.in","r",stdin);
    //freopen("travle.out","r",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            ma=max(f(a[i],a[j]),ma);
        }
    }
    cout<<ma;
    return 0;

}
