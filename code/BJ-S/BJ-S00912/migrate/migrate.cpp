#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=2e6+13;
int n,d;
int a[maxn];
int las[maxn],to[maxn];
priority_queue< pair<int,int> >q;
int cnt=0;
int work(int l,int r){
    int len=r-l+1;
    int limit=l,ans=0;
    int lasw=0,lar=0;
    for(int i=l+1;i<l+len-2;i++){
        int x1,x2,x3,x4,x5,x6,x7,x8;
        x1=las[i],x2=las[i+1],x3=to[i],x4=to[i+1];
        x5=las[i-1],x6=las[i+2],x7=to[i-1],x8=to[i+2];

        if(x1==i||x4==i+1) continue;
        x6=min(i,x6);
        x7=max(x7,i+1);
        if(x6<=x2||x7>=x3) continue;
        ans+=lasw*(x7-lar);
        lasw=x6-limit,lar=x7;
        limit=x6;
    }
    return ans+lasw*(r-lar);
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin>>c>>t;
    while(t--){
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            //cout<<a[i]<<" ";
            while(!q.empty()){
                pair<int,int>p=q.top();
                int id=p.second,wz=0-p.first;
                if(wz>=a[i]){
                    las[i]=id;
                    break;
                }
                to[id]=i-1;
                q.pop();

            }
            if(q.empty()) las[i]=i;
            q.push({0-a[i]-d,i});
            int ans=0;
            a[n+1]=(1ll<<62);
            int last=0;

        }
       // cout<<'\n';
        while(!q.empty()){
            pair<int,int>p=q.top();
            int id=p.second,wz=0-p.first;
            to[id]=n;
            q.pop();
        }
        int last=0,ans=0;
        for(int i=1;i<=n;i++){
            if(a[i+1]-a[i]>d){
                ans+=work(last+1,i);
                last=i;
            }
        }
        cout<<ans<<'\n';
       /* for(int i=1;i<=n;i++){
            cout<<las[i]<<" "<<to[i]<<'\n';
        }*/
    }
    return 0;
}
