#include<bits/stdc++.h>
using namespace std;
#define For(i,a,b) for(int i=a;i<=b;i++)
#define rep(i,a,b) for(int i=a;i>=b;i--)
#define intl long long 
#define MAXN 500005

intl n,m;
long long  a[MAXN];
long long  num[MAXN];
long long  vip[MAXN];
bool check(int i,int x){
    if(m>=num[i]-num[x]-vip[x])return 1;
    else return 0;
}
long long maxx[MAXN];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    // freopen("crystal3.in","r",stdin);
    // freopen("miao.out","w",stdout);
    //wo men bu yi yang 

    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    //zheng li you zhu shi diao de freopen
    
    cin>>n>>m;
    For(i,1,n){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    int key=a[n];
    int w=a[n];
    rep(i,n,1){
        maxx[i]=w;
        if(key>a[i]){
            w=key;
            key=a[i];
            // cout<<key<<' '<<w<<'\n';
        }
    }
    // For(i,1,n){
    //     cout<<vip[i]<<' ';
    // }
    // cout<<'\n';
    num[1]=1;
    For(i,2,n){
        num[i]=num[i-1]+(i-1)*(a[i]-a[i-1]);
        if(a[i]==a[i-1]||a[i]==a[i+1]){
            vip[i]=(maxx[i]-a[i])*(i-1);
        }
    }
    
    // For(i,1,n){
    //     if(i>=315275){
    //         if(check(i,i-315275)==1){
    //             cout<<111;
    //         }
    //     }
    // }
    // For(i,1,n){
    //     if(a[i]==a[i-1])cout<<1<<'\n';
        
    // }
    // cout<<'\n';
    intl ans=1;
    For(i,1,n){
        intl l=1,r=i;
        intl x=i;
        while(l<=r){
            intl mid=(l+r)>>1;
            if(check(i,mid)){
                r=mid-1;
                x=mid;
            }else{
                l=mid+1;
            }
        }
        ans=max(ans,i-x+1);
        // if(ans==313324){
        //     cout<<a[i]<<' '<<a[x]<<'\n';
        // }
        
    }
    cout<<ans<<'\n';

    return 0;
}
/*
5 5
1 2 4 8 9

5 8
-3 -1 2 2 7

11 1
0 2 2 2 2 3 3 3 3 3 3 

11 5
0 2 2 2 2 7 7 7 7 7 7


*/