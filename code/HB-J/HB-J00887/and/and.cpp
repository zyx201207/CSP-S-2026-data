#include<bits/stdc++.h>
using namespace std;
int n,m,a[200010],sum,sum1;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(m==1){
        cout<<max_element(a,a+n)-a;
    }
    if(m==n){
        for(int i=1;i<=n;i++){
            sum&=a[i];
        }
        cout<<sum;
    }
    if(m==2){
        int max1=0;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                max1=max(max1,a[i]&a[j]);
            }
        }
        cout<<max1;
    }
    if(m==n-1){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(j==i){
                    continue;
                }
                else{
                    sum1&=a[i];
                }
            }
        }
    }
    return 0;
}
