#include<bits/stdc++.h>
using namespace std;
int a[200010],ma=0,sum=a[1],n,m;
bool s[200010];
void f(int stanp){
    if(stanp>m){
        ma=max(sum,ma);
        return;
    }
    for(int i=1;i<=n;i++){
        if(s[i])continue;
        int y=sum;
        if(stanp==1)sum=a[i];
        sum=sum&a[i];
        s[i]=true;
        f(stanp+1);
        s[i]=false;
        sum=y;
    }
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    memset(s,false,sizeof(s));
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(m==n){
        int ans;
        for(int i=1;i<=n;i++){
            ans=ans&a[i];
        }
        cout<<ans;
        return 0;
    }
    f(1);
    cout<<ma;
    return 0;
}

