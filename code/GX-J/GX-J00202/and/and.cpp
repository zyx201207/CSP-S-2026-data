#include<bits/stdc++.h>
using namespace std;
int n,m,x,mx1;
int a[1001000];
int mx=0,cnt=0;
void p(int m){
    while(m--){
        x=0;
        mx1=0;
        for(int i=1;i<cnt;i++){
            if(mx1<=(mx & a[i])){
                   mx1=(mx & a[i]);
                   x=i;
                }
        }
        cnt=x;
        mx=mx1;
    }
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);

    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];

    }
    sort(a+1,a+n+1);

    for(int i=1;i<=n;i++){
           for(int j=i+1;j<=n;j++){
                if(mx<=(a[i] & a[j])){
                   mx=(a[i] & a[j]);
                    cnt=i;
                }
            }

    }
    m-=2;

    p(m);
    cout<<mx;
    return 0;
}

