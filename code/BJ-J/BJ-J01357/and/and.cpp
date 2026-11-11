#include <iostream>
#include <algorithm>
using namespace std;

long long maxx(long long a,long long b){

    if(a<b){
        return b;
    }
    return a;
}

int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    long long m,n;
    cin>>n>>m;
    long long a[200000];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    long long co=a[n/2];
    if(m==n){
        cout<<a[n-1];
    }
    if(m==n-1){
        cout<<a[n-2];
    }
    for(int i=n-1;i>=maxx(n-m*3-10,0);i--){
         long long mm=m;
         long long coo=0;
         while(mm>0){
            int y=i;
            coo==coo&&a[y--];
         }
         co=maxx(co,coo);
    }
    cout<<co;
}
