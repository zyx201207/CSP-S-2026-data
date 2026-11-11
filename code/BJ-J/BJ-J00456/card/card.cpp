#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005],ans[300005],mm[500005],f[500005];
struct ge{
    int aa,b,v;
}b[500005];
bool aab(ge x,ge y){
    return x.aa<y.aa;
}
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    int cnt=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(mm[a[i]]){
            b[i].aa=mm[a[i]];
            b[i].b=i;
            b[i].v=a[i];
            cnt++;
        }
        mm[a[i]]=i;
    }
    sort(b+1,b+cnt+1,aab);
    if(m<=2){
        if(a[1]!=a[n]) {
            ans[1]++;
            ans[2]++;
        }
        else if(a[1]==a[n])
        {
            ans[a[1]]++;
        }
    }
    else{
        int k=1;
        for(int i=1;i<=n;i++){
            ans[a[i]]++;
            ans[a[n]]++;
            for(int iz=1;iz<=n;iz++)
            {

                f[iz]=0;
            }
            for(int j=i+1;j<n;j++)
            {
                if(f[a[j]]==0){
                int flag=1;
                for(int k=1;k<n-1;k++)
                {
                    if(b[k].aa>=i&&b[k].aa<j&&b[k].b>a[k]){
                        flag=0;
                        break;
                    }
                }
                if(flag&&f[a[j]]==0){
                    ans[a[j]]++;
                    f[a[j]]=1;
                }

                }
            }
        }
    }
    for(int i=1;i<=m;i++)
    {

        cout<<ans[i]<<" ";
    }
    return 0;
}
