#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,m;

struct N{
    ll e,r1;
}a[200010];
void f(int i){
    ll y=a[i].e;
    while(y){
        if(y%2==1) a[i].r1++;
        y/=2;
    }
}
bool cmp1(N a,N b){
    if(a.r1==b.r1) return a.e>b.e;
    else return a.r1>b.r1;
}
bool cmp2(N a,N b){
    return a.e>b.e;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    int bo=1;
    for(int i=1;i<=n;i++){
        cin>>a[i].e;
        if(a[i].e!=i-1){
            bo=0;
        }
        f(i);
    }
    if(bo){
        sort(a+1,a+1+n,cmp2);
    }else{
        sort(a+1,a+1+n,cmp1);
    }
    for(int i=1;i<=n;i++){
        //cout<<a[i].e<<" ";
    }
    ll ans=a[1].e;
    if(m==1) {
        cout<<a[1].e;
    }else{
        for(int i=2;i<=m;i++){
            ans&=a[i].e;
            //cout<<a[i].e<<" ";
        }
    }
    cout<<ans<<endl;

    return 0;
}
