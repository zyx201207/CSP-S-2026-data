#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+5;
int n,m,a[N],tjt;
bool cmp(int x,int y){
    x=tjt-x,y=tjt-y;
    if(x>=0&&y>=0)
        return x<y;
    return y<0;
}
void sov1(){
    int maxx=-1e9,minx=1e9,ans=0;
    for(int i=1;i<=n;i++)
        maxx=max(maxx,a[i]),minx=min(minx,a[i]);
    for(tjt=minx;tjt<=maxx;tjt++){
        int cnt=0,mm=m;
        sort(a+1,a+n+1);
        int ed=n;
        for(int i=1;i<=n;i++)
           if(a[i]>tjt){
                ed=i-1;
                break;
           }
        if(ed==1){
            ans=max(ans,1LL);
            continue;
        }
        sort(a+1,a+n+1,cmp);
        for(int i=1;i<=n&&tjt-a[i]>=0;i++){
            if(mm>=tjt-a[i])
                mm-=tjt-a[i],cnt++;
            else
                break;
        }
        ans=max(ans,cnt);
    }
    cout<<ans<<endl;
}
void sov2(){
    for(int i=1;i<=n;i++){
        int x=(1+i)*i/2;
        if(x>m){
            cout<<i<<endl;
            break;
        }
        if(x==m){
            cout<<i+1<<endl;
            break;
        }
    }
}
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    if(n<=10000)
        sov1();
    else
        sov2();
    return 0;
}
