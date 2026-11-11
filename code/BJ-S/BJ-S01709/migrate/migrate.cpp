#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,a[2000005],ls,ans,da,y;
int road(int x,int s){
    if(x==y){
        if(s==ls){
            ans++;
        }
        else if(s<ls){
            ls=s;
            ans=1;
        }
        return 0;
    }
    for(int i=x+1;i<=y;i++){
        if(a[i]-a[x]<=d){
            road(i,s+1);
        }
    }
    return 0;
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        da=0;
        cin>>n>>d;
        for(int k=1;k<=n;k++){
            cin>>a[k];
        }
        for(int i=1;i<=n;i++){
                for(int j=i+1;j<=n;j++){
                    ls=2147483646;
                    ans=0;
                    y=max(i,j);
                    road(min(i,j),0);
                    if(ans==2){
                        da++;
                    }
                }
            }
        cout<<da<<endl;
    }
    return 0;
}
