#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    long long n,m,a[10000005];
    int cnt,cnt1;
    string b[10000000],c[1000000];
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    while(cnt>0){
        int i=1;
        cnt=a[i]/2;
        b[i]+=a[i]%2;
        i++;
    }
    for(int i=1;i<=n;i++){
        if(i!=n)
            c[i]=b[i]||b[i+1] ;

    }
    return 0;
}
