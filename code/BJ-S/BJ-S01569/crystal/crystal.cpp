#include<iostream>
using namespace std;
long long n,m,a[500001];
int ans=0;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=n;i>=1;i--)
    {
        if(ans>=i)break;
        int pos=a[i],j=i-1,cnt=1,m1=m;
        while(j>=1)
        {
            if(m1<pos-a[j])break;
            m1-=pos-a[j];
            j--;
            cnt++;
        }
        //cout<<"cnt:"<<cnt<<"\n";
        ans=max(ans,cnt);
    }
    cout<<ans;
    return 0;
}