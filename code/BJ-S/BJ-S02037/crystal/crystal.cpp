#include<bits/stdc++.h>
using namespace std;

int n,m,x,sum=0,sum1=0,sum2=0,ans=0;
int a[500005],b[500005],c[500005];
bool f=0;

int main(){

    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        c[i]=a[i];
    }
    sort(a+1,a+n+1);
    sort(c+1,c+n+1);
    x=m;
    for(int i=1;i<=n;i++){
        //sum=0;
        for(int j=1;j<=i;j++){
            if(m==0){
                break;
            }
            if(a[j+1]-a[j]>m){
                f=1;
                break;
            }
            if(a[j]<a[j+1]){
                a[j]++;
                m--;
            }
        }
            for(int j=2;j<=n;j++){
                if(a[j-1]!=a[j]){
                    break;
                }
                sum++;
            }
            sum1=max(sum,sum1);
            f=0;
    }
    for(int i=1;i<=n;i++){
        //sum=0;
        for(int j=i;j>=1;j--){
            if(x==0){
                break;
            }
            if(c[j]-c[j-1]>x){
                f=1;
                break;
            }
            if(c[j-1]<c[j]){
                c[j-1]++;
                x--;
            }
        }
            for(int j=n;j>=1;j--){
                if(a[j-1]!=a[j]){
                    break;
                }
                sum++;
            }
            sum2=max(sum,sum2);
            f=0;
    }


    ans=max(sum1,sum2);
    cout<<ans;
    return 0;
}
