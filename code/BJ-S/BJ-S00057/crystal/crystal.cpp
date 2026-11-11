#include<bits/stdc++.h>
using namespace std;
const long long N=5*1e5;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long n,m;
    cin >> n >> m;
    double a[N]={};
    double sum=0;
    for(long long i=1;i<=n;i++){
        cin >> a[i];
        sum+=a[i];
    }
    sort(a+1,a+n+1);
    sum=sum/(1.0*n);
    long long mis=10000000001,y,k;
    for(long long i=n/2,j=n/2+1;i>=1,j<=n;i--,j++){
        double x1=abs(a[i]-sum),x2=abs(a[j]-sum);
        if(x1<=x2){
            if(x1<mis){
                y=a[i];
                k=i;
                mis=x1;
            }
        }else{
            if(x2<mis){
                y=a[j];
                k=j;
                mis=x2;
            }
        }
    }
    long long cnt=1;
    for(long long i=k-1;i>=1;i--){
        long long z=y-a[i];
        if(m>=z){
            m-=z;
            cnt++;
        }else{
            break;
        }
    }
    for(long long i=k+1;i<=n;i++){
        if(a[i]==y){
            cnt++;
        }else{
            break;
        }
    }
    cout<<cnt;
    return 0;
}
