#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m,x=0;
    cin>>n>>m;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        int k=a[i];
        for(int j=i+1;j<=i+m-1;j++){
                k=k&a[j];
        }
        if(k>x){
            x=k;
        }
    }
    cout<<x;
    return 0;
}
