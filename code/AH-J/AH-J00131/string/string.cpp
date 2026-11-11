#include<bits/stdc++.h>
using namespace std;
int n;
long long sum;
struct node{
    int x;
    char y;
}a[200005];
int main()
{
    int ans;
    char b;
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++)    cin>>a[i].x>>a[i].y;
   /* for(int i=0;i<n/2;i++)
    {
        if(a[i].x==a[n-i-1].x&&a[i].y!=a[n-i-1].y)
        {
            if(ans>0&&b==a[i].y)sum-=ans;
            sum+=a[i].x;
        }
    }*/
    string s;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<a[i].x;j++)
        {
            s+=a[i].y;
        }
    }
    for(int i=0;i<s.size()/2;i++)
    {
        if(s[i]!=s[s.size()-i-1])
        {
            sum++;
        }
    }
    cout<<sum;
    return 0;
}
