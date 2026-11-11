#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+5;
int c,T,n,d,a[N],dis[N];
bool check(int l,int r){
    int len=99;
    for(int i=0;i<(1<<(r-l-1));i++){
        int x=0,f=1,lst=l;
        for(int j=0;j<=(r-l-1);j++){
            if((1<<j)&i){
                    x++;
            if(a[l+j+1]-a[lst]>d){
                f=0;
                break;
            }
            lst=l+j+1;
            }
        }
        if(a[r]-a[lst]>d)f=0;
        if(f){

            len=min(len,x);
        }
    }
    if(len==0)return 0;
    int flag=0;
    for(int i=0;i<(1<<(r-l-1));i++){
        int x=0,lst=l,f=1;
       for(int j=0;j<=(r-l-1);j++){
            if((1<<j)&i){
                    x++;
            if(a[l+j+1]-a[lst]>d){
                f=0;
                break;
            }
            lst=l+j+1;
            }
        }
        if(a[r]-a[lst]>d)f=0;
        if(f){
            if(x==len)flag++;
        }
    }
    return flag==2;
}
/*
0 2 4 2
1 2 3 4
*/
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin>>c>>T;
    while(T--){
        cin>>n>>d;
        if(c<=2){
                int ans=0;
            for(int i=1;i<=n;i++)cin>>a[i];
            for(int l=1;l<n;l++){
                for(int r=l+1;r<=n;r++){
                    ans+=check(l,r);
                }
            }
            cout<<ans<<"\n";
        }else if(c==13||c==14){
            /*
            13 1
            10 4
            1 1 1 3 5  6 9 9 9 9
            */

            int dcnt=0,did1=0,did2=0,ans=0;

            for(int i=1;i<=n;i++)cin>>a[i];
            for(int i=1;i<=n;i++){
                if(abs(a[i]-a[1])<=d&&abs(a[n]-a[i])<=d){
                    if(!did1)did1=i;
                    dcnt++;
                    did2=i;
                }
            }
            if(dcnt==1){
                int ct=lower_bound(a+1,a+1+n,a[did1-1]+d+1)-1-a;
                int ct2=lower_bound(a+1,a+1+n,a[did1-2]+d+1)-1-a;
                int dt=ct-ct2;
                bool f=0;
                for(int i=1;i<=n;i++){
                    if(abs(a[did1+1]-a[i])<=d)f=1;
                    if(abs(a[did1+2]-a[i])<=d)break;
                    if(!f){
                        ans+=dt;
                    }else{
                        ans+=n-ct;
                    }
                }
                cout<<ans<<"\n";
            }else if(dcnt==2){
                int ct=lower_bound(a+1,a+1+n,a[did1-1]+d+1)-1-a;
                for(int i=1;i<=n;i++){
                    if(abs(a[did2+1]-a[i])<=d)break;
                    ans += n-ct;
                }
                cout<<ans<<"\n";
            }else{
                cout<<0<<"\n";
            }
        }else{
            for(int i=1;i<=n;i++)cin>>a[i];
            int jp=d/(a[2]-a[1]),ans=0;
            if(jp==0||jp==1){
                cout<<0<<"\n";
                continue;
            }
            for(int i=1;i<=n;i++){
                if(n-i>=jp+jp-1)ans++;
            }
            cout<<ans<<"\n";
        }
    }
    return 0;
}
//10pts
