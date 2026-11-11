#include<bits/stdc++.h>
using namespace std;
int a[i];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w,"stdout);
    int n,m,sum=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<n;i++){
        for(j=1;j<=n;j++){
            if(a[i]==a[j]){
                if(sum>a[i]){
                    sum=a[i];
                }
            }
            if(a[i]/a[j]>=1){
                sum>a[i];
            }
        }
    }
    cout<<sum;
    return 0;
}
