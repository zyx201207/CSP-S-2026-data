#include<bits/stdc++.h>
using namespace std;
long long a[200001];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    long long n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    long long man=a[0];
    for(int i=1;i<=n;i++){
        if(a[i]==man){
            cout<<a[i];
            return 0;
        }else{
            man=a[i];
        }
    }
    cout<<man;
    return 0;
}
