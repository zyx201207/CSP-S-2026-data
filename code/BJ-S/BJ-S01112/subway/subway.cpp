#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,k,t;
int w[500005];
int a[500005];
int x[500005];
int y[100005];
int vis;
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
            cin>>k;
        for(int j=1;j<=(2*k)+1;j++){
            cin>>a[j]>>t;
            for(int e=1;e<=(2*k)+1;e++){
                if(a[j]==a[e]){
                    vis=a[j];
                }
            }
        }

    }
    int cnt=0;

    for(int i=1;i<=q;i++){
        int sum=0;
        cin>>x[i]>>y[i];
        cnt=(t*(vis-x[i]))+(t*(y[i]-vis));
        sum=w[a[x[i]]]+w[a[y[i]]]+cnt;
        cout<<sum;
    }

    return 0;
}
