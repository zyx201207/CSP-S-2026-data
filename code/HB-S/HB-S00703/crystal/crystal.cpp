#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[500010];
int b[500010];
signed main(){
    freopen("crystal4.in","r",stdin);
    //freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    if(n==1){
        cout<<1;
        return 0;
    }
    bool flag=true;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=2;i<n;i++){
        if(a[i+1]-a[i]!=a[i]-a[i-1]){
            flag=false;
        }
    }
    bool out=0;
    if(flag==true){
        int d=a[2]-a[1];
        for(int i=1;i<=sqrt(m)+1;i++){
            if((a[i]*(a[i]+d)<m&&a[i+1]*(a[i+1]+d)>m)){
                cout<<i+1;
                out=1;
                return 0;
            }
            else if(a[i]*(a[i]+d)==m){
                cout<<i+2;
                out=1;
                return 0;
            }
        }
    }else{
        for(int i=2;i<=n;i++){
            int num=0;
            bool pd=0;
            for(int j=i-1;j>=1;j--){
                b[j]=a[i]-a[j];
                if(pd==1){
                    continue;
                }
                else{
                    if(b[j]==0){
                        num++;
                    }
                    else{
                        pd=1;
                    }
                }
            }
            int sum=0;
            for(int j=1;j<=i-1;j++){
                sum+=b[j];
            }
            if(sum>m){
                cout<<i-num;
                out=1;
                return 0;
            }
            else if(sum==m){
                cout<<i;
                out=1;
                return 0;
            }
        }
    }
    if(out==0){
        cout<<1;
    }
    return 0;
}
