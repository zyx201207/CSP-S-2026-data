#include <bits/stdc++.h>
using namespace std;
#define int long long
int t,c;
int a[2000005];
struct node{
    int from,to,sz;
}b[100000000];
bool cmp(node x,node y){
    if(x.from!=y.from) return x.from<y.from;
    else{
        return x.to<y.to;
    }
}
signed main(){
    freopen("migrate.in",'r',stdin);
    freopen("migrate.out",'w',stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>c>>t;
    int n,d;
    while(t>0){
        t--;
        cin>>n>>d;
        for(int i=1;i<=n;i++) cin>>a[i];
        for(int i=1;i<n;i++){
            for(int j=i+1;j<=n;j++){
                b[(i-1)*n+j].from=a[i];
                b[(i-1)*n+j].to=a[j];
                b[(i-1)*n+j].sz=abs(a[i]-a[j]);
            }
        }
        sort(b+1,b+n*(n-1)/2+1,cmp);
        int ans=0,ansn=0;
        for(int l=1;l<=n;l++){
            for(int r=l;r<=n;r++){
                for(int i=1;i<=n*(n-1)/2;i++){
                    for(int j=1;j<=n*(n-1)/2;j++){
                        if(b[i].from==l&&b[j].from==b[i].to&&b[j].to==r){
                            ans++;
                        }
                    }
                }
                if(ans==2) ansn++;
                ans=0;
            }
        }
        cout<<ansn<<"\n";
        memset(b,0,sizeof(b));
        ansn=0;
        n=0;
        c=0;
    }
    return 0;
}
