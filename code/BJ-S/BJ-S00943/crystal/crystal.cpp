#include <bits/stdc++.h>
using namespace std;
long long m,a[500005];
int n,b;
bool A=1,B=1;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]!=i){
            A=0;
        }
        if(i>1){
            if(a[2]-a[1]!=a[i]-a[i-1]){
                B=0;
            }
        }
    }
    if(A){
        while(m>0 && b<n){
            b++;
            m-=b;
        }
        if(m<0){
            b--;
        }
        cout<<++b;
        return 0;
    }
    if(B){
        b=m/(a[2]-a[1]);
        cout<<min(b,n);
        return 0;
    }
    sort(a+1,a+n+1);
    while(m>0 && b<=n){
        b++;
        m-=(a[b+1]-a[b])*b;
        a[b]=a[b+1];
    }
    while(a[b+1]==a[b]){
        b++;
    }
    if(m<0){
        b--;
    }
    cout<<b;
    return 0;
}
