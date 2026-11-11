#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,m,a[N];
int main(){
    int s=0;
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    for(int i=1;i<=n;i++){
        if(a[i]<a[i+1]){
            s=1;
        }
        else{
            s=0;
        }
    }
    if(s==1){
        for(int i=n;i>=1;i--){
            cout<<i<<" ";
        }
        return 0;
    }
}
