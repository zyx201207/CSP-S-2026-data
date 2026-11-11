#include <bits/stdc++.h>
using namespace std;
int a[100000005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int sum=0;
    if(m==1){
        cout<<n;
    }else if(m==2){
        if(a[n-1]==1){
            for(int i=0;i<=n-2;i++){
                if(a[i]==2)sum++;
            }
            cout<<n<<" "<<sum;
        }else if(a[n-1]==2){
            for(int i=0;i<=n-2;i++){
                if(a[i]==1)sum++;
            }
            cout<<sum<<" "<<n;
        }
    }
    return 0;
}
