//something wrong but ok
#include<bits/stdc++.h>
#define int long long
using namespace std;

int n,cnt=0,ans=0;
int a[200005]={},pre[200005]={};
int e;
char c[200005]={};

char f(int ind){
    for(int i=1;i<=e;++i){
        if(pre[i-1]<ind&&pre[i]>=ind){
            return c[i];
        }
    }
}//a 2 2 1
//pre 2 4 5

signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;++i){
        cin>>a[e];
        cin>>c[e];
        cnt+=a[e];
        if(c[e]==c[e-1]){
            a[e-1]+=a[e];
            pre[e-1]+=a[e];
        }
        else{
            pre[e]=pre[e-1]+a[e];
            ++e;
        }
        //cout<<i<<endl;
    }
    //cout<<"a"<<endl;
    for(int i=1;i<=cnt/2;++i){
        if(f(i)!=f(cnt-i+1)){
            ++ans;
        }
    }
    cout<<ans;
    return 0;
}
