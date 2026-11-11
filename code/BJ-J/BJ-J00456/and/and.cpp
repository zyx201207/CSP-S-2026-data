#include<bits/stdc++.h>
using namespace std;
int a[200005],b[5],c[30],l;
int ans=0;
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int maxx=0,flag=1;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]>maxx) maxx=a[i];
        if(a[i]<4) b[a[i]]++;
        else flag=0;
    }
    if(m==1){
        cout<<maxx;
    }
    else if(m==n)
    {
        ans=a[1];
        for(int i=2;i<=n;i++)
        {
            ans=ans&a[i];
        }
        cout<<ans;
    }
    else if(m==2){
        for(int i=1;i<=n;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
                if(a[i]&a[j]>ans) ans=a[i]&a[j];
            }
        }
        cout<<ans;
    }
    else if(m=n-1)
    {
        for(int i=1;i<=n;i++)
        {
            l=a[1];
            if(i==1){
                l=a[2];
                for(int j=3;j<=n;j++){
                    l=l&a[i];
                }
            }
            else{
            for(int j=2;j<=n;j++){
                if(j==i) continue;
                l=l&a[i];
            }}
            if(l>ans) ans=l;
        }
        cout<<ans;
    }
    else if(a[2]&a[3]==min(a[2],a[3])&&a[13]&a[28]==min(a[13],a[28])){
        sort(a+1,a+n+1);
        cout<<a[n-m+1];
    }
    else if(flag){
        if(a[3]>=m) {cout<<3;}
        else if(a[3]+a[2]>=m) {cout<<2;}
        else cout<<1;
    }
    return 0;
}