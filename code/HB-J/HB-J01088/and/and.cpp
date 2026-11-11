#include <bits/stdc++.h>
using namespace std;
int a[200005];
int b[20],c[20];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for (int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    int j=1;
     while (a[n]>1){
            b[j]=a[n]%2;
            a[n]/=2;
            j++;
        }
    for (int i=n-1;i>=n-m+1;){
        if (a[i]%2==0){
          j=1;
          while (a[i]>1){
             c[j]=a[i]%2;
             a[i]/=2;
             j++;
         }
         i--;
        }
        for (int k=j;k>=1;k--){
            if (b[k]==c[k]) b[k]==1;
            else b[k]==0;
        }

    }
    int sum=1;
    for (int i=j-1;j>=1;j--){
        int num=1,shu=2;
        for (int k=1;k<=num;k++){
            shu*=2;
        }
        sum+=b[i]*shu;
    }
    cout<<sum;
    return 0;

}
