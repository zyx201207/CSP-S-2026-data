#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[200010];
struct node{
    int l,r;
}q[200010],p[200010];
int k;
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin>>c>>t;
    while(t--){
        int n,d;
        cin>>n>>d;
        k=0;
        q[++k].l=1;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            if(i>1&&a[i]-a[i-1]>d) q[k].r=i-1,q[++k].l=i;
        }
        q[k].r=n;
        int ans=0;
        for(int ww=1;ww<=k;ww++){
            int l=q[ww].l,r=q[ww].r;
            int lst=l,sum=0,t=0;
            bool flag=0,ff=0,fff=0;
            for(int i=l+2;i<=r;i++){
                if(a[i]-a[i-2]<=d){
                    if(lst<i-2||lst==l) p[++t].l=lst,p[t].r=i-2,lst=i,flag=0,fff=0;
                    else{
                        if(a[i]-a[p[t].r]>d&&!fff) ans+=1;
                        else fff=1;
                        lst=i,flag=1;
                        if(i==l+2) ff=1;
                    }
                }
            }
            if(!flag) p[++t].l=lst,p[t].r=n;
            for(int i=1;i<t;i++){
                if(i==1&&ff) continue;
                int x=(p[i].r-p[i].l+1);
                int y=(p[i+1].r-p[i+1].l+1);
                sum+=x*y;
            }
            ans+=sum;
        }
        cout<<ans<<"\n";
    }
    return 0;
}