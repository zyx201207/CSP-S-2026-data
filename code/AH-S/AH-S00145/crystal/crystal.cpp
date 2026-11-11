#include<bits/stdc++.h>
using namespace std;
int a[100];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    int cnt=a[n/2];
    for(int i=1;i<=n;i++){
        if(m!=0&&a[i]<cnt){
            int q=cnt-a[i];
            a[i]+=q;
            m-=q;
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        if(a[i]==cnt) ans++;
    }
    cout<<ans;
    return 0;
}
