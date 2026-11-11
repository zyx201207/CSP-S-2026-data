#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,ans=1;
long long m,a[N],d[N];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    bool flag=0;
    d[1]=a[1];
    for(int i=2;i<=n;i++){
        d[i]=a[i]-a[i-1];
        if(d[i]!=d[i-1]) flag=1;
    }
    if(flag){
        for(int i=1;i<=n;i++){
            long long sum=0;
            bool op=0;
            for(int j=i;j>=i-ans+1;j--){
                sum+=(ans+j-i)*d[j];
                if(sum>m){
                    op=1;
                    break;
                }
            }
            if(op==1) continue;
            else{
                for(int j=ans+1;j<=i;j++){
                    sum=0;
                    for(int k=i;k>=i-j+1;k--){
                        sum+=(j+k-i)*d[k];
                        if(sum>m){
                            op=1;
                            break;
                        }
                    }
                    if(op==1){
                        ans=j-1;
                        break;
                    }
                }
            }
        }
        cout<<ans+1;
    }else{
        for(int i=1;i<=n;i++){
            long long x=i*i+i;
            int p=a[2]-a[1];
            if(x>2*m/p){
                ans=i-1;
                break;
            }
        }
        cout<<ans+1;
    }
    return 0;
}
