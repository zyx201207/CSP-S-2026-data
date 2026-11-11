#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
long long c,t,a[500005];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--)
    {
        long long n,d,ans=0;
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            if(i>=4)
                if(a[i]-a[i-3]>d)
                    if(a[i]-a[i-1]<=d&&a[i-1]-a[i-2]<=d)
                        ans++;
        }
        if(t!=0)cout<<ans<<endl;
        else cout<<ans;
    }
    return 0;
}

