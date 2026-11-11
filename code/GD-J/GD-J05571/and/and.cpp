#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    long long n,m;
    cin>>n>>m;
    long long h[n];
    long long k;
    for(int i=0;i<n;i++){
        cin>>h[i];
    }
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-1;j++){
            if(h[j]<h[j+1]){
                k=h[j+1];
                h[j+1]=h[j];
                h[j]=k;
            }
        }
    }
    cout<<endl;
    cout<<h[0];
    return 0;
}
