#include<bits/stdc++.h>
using namespace std;
int a[200010];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int sum = 0;
    int sum1 = 0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=0;j<m;j++){
            if(i+j<=n&&sum==0){
                sum==a[i+j];
            }else if(i+j<=n){
                sum&=a[i+j];
            }
        }
        if(sum>sum1){
            sum1 = sum;
        }
        sum = 0;
    }
    cout<<sum1;
return 0;
}
