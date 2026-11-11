#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
long long n,m,a[N],my_shu=1,my_cha[5005][5005];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        for(int j=i;j<n;j++){
            my_cha[i][j]=a[i+1]-a[i]+my_cha[i][j-1];
        }
    }
    for(int i=2;i<=n;i++){
        for(int j=1;j<n;j++){
            int sum=0;
            for(int k=1;k<i;k++){
                sum=my_cha[k][j]+sum;
            }
            if(sum==m){
                my_shu=i;
                break;
            }
        }
    }
    cout<<my_shu;
    return 0;
}
