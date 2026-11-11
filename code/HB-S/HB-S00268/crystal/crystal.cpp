#include<bits/stdc++.h>
using namespace std;
long long a[500010],endans=0,n,m;
int main(){
    //
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    //
    cin>>n>>m;
    for(long long i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        long long x=m;
        int ans=1;
        for(int j=1;j<=n;j++){
            for(int k=1;k<=x;k++){
                if(a[j]+k==a[i]){
                    x-=k;
                    if(x>=0){
                        ans++;
                    }
                }
            }
        }
        if(ans>endans) endans=ans;
    }
    cout<<endans;
    return 0;
}
