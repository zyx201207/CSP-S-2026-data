#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m,z=0;
    cin>>n>>m;
    long long a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(a[i]>z){
            z=a[i];
        }
    }
    cout<<z;
}
