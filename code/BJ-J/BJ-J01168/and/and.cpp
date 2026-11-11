#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e6;
ll n,m,a[N],res=1;

int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);

    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(m==n){
        res=a[1];
        for(int i=2;i<=n;i++){
            res&=a[i];
        }
    }
    if(m==1){
        res=a[1];
        for(int i=1;i<=n;i++){
            res=max(res,a[i]);
        }
    }
    if(m==2){
        res=0;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                res=max(res,a[i]&a[j]);
            }
        }
    }
    cout<<res;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
