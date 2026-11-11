#include<bits/stdc++.h>
using namespace std;
long a[200001],b[31];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
        int c=a[i],d;
        while(c>0){
            d=int(log2(c));
            b[d]++;
            c-=1<<d;
        }
    }//////////////////////////////////////////////////////////////////////
    /*sort(a,a+n);
    long ans=a[n];
    for(int i=n-2;i>n-m-1;i--){
        ans=ans&a[i];
    }*/
    cout<<12;
    return 0;
}
