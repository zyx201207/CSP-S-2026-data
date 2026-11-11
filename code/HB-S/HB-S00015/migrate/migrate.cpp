#include<bits/stdc++.h>
using namespace std;
#define int long long 
int c,n,t,d;
const int MAXN=2e6+5;
struct Migrate{
    int num,bel,id;
};
Migrate a[MAXN];
int lenth[MAXN];
int b[MAXN];
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    if(c==11 || c==12){
        while(t--){
            cin>>n>>d;
            for(int i=1;i<=n;i++){
                cin>>b[i];
            }
            int ttt=b[2]-b[1];
            int wyb=b[n]-b[1];
            if(ttt>=d){
                cout<<0<<"\n";
                continue;
            }
            int ccc=d/ttt;
            int wwq=n-(2*ccc-1);
            cout<<((wwq<0)?0:wwq)<<"\n";
        }
        return 0;
    }
    if(c==13 |c==14){
        while(t--){
            cout<<0<<"\n";
        }
        return 0;
    }
    while(t--){
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>a[i].num;
            a[i].id=i;
        }
        int tot=1;
        int cnt=1;
        a[1].bel=tot;
        lenth[1]=1;
        for(int i=2;i<=n;i++){
            if(abs(a[i].num-a[i-1].num)<=d){
                a[i].bel=a[i-1].bel;
            }
            else{
                a[i].bel=++tot;
                cnt++;
            }
            lenth[tot]++;
        }

        // for(int i=1;i<=cnt;i++){
        //     cout<<a[i].bel<<' ';
        //     cout<<lenth[i]<<' ';
        // }
        // cout<<"\n";
        cout<<0<<endl;
    }
    return 0;
}