#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n,m,a[100005],sum=0;
    cin>>n>>m;
    for(int i = 1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i = 1;i<=n;i++)
    {
        if(a[i]<a[i+1])
        {
            int t=a[i];
            a[i]=a[i+1];
            a[i+1]=t;
        }
    }
    for(int i = m;i>0;i--)
    {
        if(a[1]<a[1+2])
        {
            a[1]++;
        }
        if(a[1]==a[1+2])
        {
            sum+=1;
            a[2]++;
        }
        if(a[2]==a[3])
        {
            sum+=1;
        }
    }
    cout<<sum;
    return 0;
}
