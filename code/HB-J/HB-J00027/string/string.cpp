#include<bits/stdc++.h>
using namespace std;
long long cinn,n=0,lsf,ans,a[10000005];
char lss;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>cinn;

  for(int i=1;i<=cinn;i++){
        cin>>lsf>>lss;
        if(lsf>10000005/cinn+1000000){
            cout<<0;
        }
        for(int j=1;j<=lsf;j++){
            n++;
            a[n]=lss;

        }

   }
    int j=n-1;
    for(int i=1;i<=n;i++){

        if(i==j){
            break;
        }
        if(i>j)break;
        if(a[i]!=a[j]){
            ans++;

        }
        j--;

    }
    cout<<ans;
}
