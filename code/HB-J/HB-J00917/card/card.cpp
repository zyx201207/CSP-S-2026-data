#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n;
    cin>>n;
    int a[0];
    int ans=0;
    for(int i=i-1;i<=n;i++){
            int a[i];
        if(i=0){
            a[i]=a[i]+i;
            ans++;
        }else if(i==1){
            a[i]=a[i]-i;
            ans-=ans-i%10/10;
            break;

        if(n==0){
            cout<<i<<" "<<a[i]<<" "<<ans;
    }
        }
    }return 0;
}
