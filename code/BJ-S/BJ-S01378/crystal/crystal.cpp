#include<bits/stdc++.h>
using namespace std;
long long m,n,a[500005],mina=1000000000001;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);int ans=0;
    cin.tie(0);cout.tie(0);cin>>n>>m;
    bool flag=true,flag2=true;int ac=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];mina=min(mina,a[i]);
        if(a[i]!=i)flag=false;
        if(a[i]-a[i-1]!=ac&&i>2)flag2=false;
        else ac=a[i]-a[i-1];
    }
    if(flag){
        for(int i=1;i<=n;i++){
            if(m>=i){m-=i;ans++;}
            else break;
        }
        cout<<ans;
        return 0;
    }else if(flag2){
        for(int i=1;i<=n;i++){
            if(m>=ac*i){m-=ac*i;ans++;}
            else break;
        }
        cout<<ans;
        return 0;
    }
    sort(a+1,a+n+1);
    while(m>0){
        for(int i=1;i<=n&&m>0;i++){
            if(a[i]<=mina){
                a[i]++;m--;
            }
        }mina++;
    }for(int i=1;i<=n;i++){
        if(a[i]==mina)ans++;
    }
    cout<<ans;
    return 0;
}
