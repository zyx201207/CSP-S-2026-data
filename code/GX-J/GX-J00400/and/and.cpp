#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,a,m,s;
    cin>>n>>a;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        m=a[i]+a[i+1];
        s=m;
        if(s>m){
            m=s;
        }
    }
    cout<<m;
    return 0;
}
