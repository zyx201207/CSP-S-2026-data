#include<bits/stdc++.h>
#define ll long long

using namespace std;
ll n,m;
ll a[500005],s[500005];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    int maxappear=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    int ans=0,sum=0;
    int num=0;
    s[1]=a[1];
    for(int i=2;i<=n;i++)
    {
        s[i]=s[i-1]+a[i];
    }
    int i=1;
    while(((ll)s[i]+m)/i>=a[i+1])
        i++;
    num=i;
    int j=num;
    while(a[j+1]==a[j])
        num++;
    cout<<num<<endl;
    return 0;
}
//g++ -o crystal crystal.cpp -O2 -std=c++14 -static