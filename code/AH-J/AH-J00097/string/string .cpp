#include<bits/stdc++.h>
#define int long long
using namespace std;
struct node{
    int a;
    char c;
}x[200005];
struct dep{
    int res,cnt,tot;
}l,r;
int n,sum,ans;
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>x[i].a>>x[i].c,sum+=x[i].a;
    sum=sum/2;
    l.res=1,l.cnt=x[1].a,r.res=n,r.cnt=x[n].a;
    while(l.tot<=sum&&r.tot<=sum&&l.res<r.res){
        if(l.res==r.res) break;
        if(l.cnt>r.cnt){
            if(x[l.res].c!=x[r.res].c) ans+=r.cnt;
            l.cnt-=r.cnt;
            l.tot+=r.cnt;
            r.tot+=r.cnt;
            r.res--;
            r.cnt=x[r.res].a;
        }else if(l.cnt<r.cnt){
            if(x[l.res].c!=x[r.res].c) ans+=l.cnt;
            r.cnt-=l.cnt;
            l.tot+=l.cnt;
            r.tot+=l.cnt;
            l.res++;
            l.cnt=x[l.res].a;
        }else if(l.cnt==r.cnt){
            if(x[l.res].c!=x[r.res].c) ans+=l.cnt;
            l.tot+=l.cnt;
            r.tot+=r.cnt;
            l.res++;
            r.res--;
            l.cnt=x[l.res].a;
            r.cnt=x[r.res].a;
        }
    }
    cout<<ans;
    return 0;
}
