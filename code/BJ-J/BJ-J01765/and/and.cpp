#include <bits/stdc++.h>
using namespace std;
int n,m,a[2000005],b[2000005],ans;
int ling;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    if(m==n)
    {
        ans=a[1];
        if(a[1]==0)
        {
            cout<<0;
            return 0;
        }
        for(int i=2;i<=n;i++)
        {
            ans&=a[i];
            if(ans&a[i]==0)
            {
                cout<<0;
                return 0;
            }
        }
        cout<<ans;
        return 0;
    }
    if(m==2)
    {
        int maxx=0;
        for(int i=1;i<n;i++)
        {
            for(int j=i+1;j<=n;j++){
                maxx=max(maxx,a[j]&a[i]);
            }
        }
        cout<<maxx;
        return 0;
    }
    int ans=a[n];
    int mm=m;
    for(int j=n-1;j>=m;j--){
        if(ans&a[j]==0)
        {
            m--;
            ling++;
            if(m==0)
            {
                if(ling>=n-mm)
                {
                    cout<<0;
                    return 0;
                }
                else{
                    cout<<1;
                    return 0;
                }
            }
            continue;
        }
        else if(ans&a[j]==1)
        {
            m--;
            if(m==0)
            {
                if(ling>=n-mm)
                {
                    cout<<0;
                    return 0;
                }
                else{
                    cout<<1;
                    return 0;
                }
            }
            continue;
        }
        ans&=a[j];
    }
    cout<<ans;
    return 0;
}

