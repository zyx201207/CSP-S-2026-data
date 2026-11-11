#include<bits/stdc++.h>
using namespace std;
int n;
struct pir{int x;char a;};
pir a[200005];
int main()
{
    freopen("string.in",'r',stdin);
    freopen("string.out",'w',stdout);
    cin>>n;
    for(int i = 1;i<=n;i++) cin>>a[i].x>>a[i].a;
    int l=1,r=n;
    long long ct = 0;
    while(l<r)
    {
        //cout<<a[l].a<<' '<<a[l].x<<' '<<a[r].a<<' '<<a[r].x<<endl;
        if(a[l].a != a[r].a)
        {
            ct+=min(a[l].x,a[r].x);
        }
        if(a[l].x>a[r].x)
        {
            a[l].x-=a[r].x;
            r--;
        }
        else if(a[l].x==a[r].x)
        {
            l++;
            r--;
        }
        else
        {
            a[r].x-=a[l].x;
            l++;
        }
    }
    cout<<ct;
}
