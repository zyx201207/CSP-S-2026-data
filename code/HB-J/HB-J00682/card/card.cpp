#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500005],c[500005];
int kl(int x){
    long long r=0,l=0,num=-1;
    if(x==n){
        c[a[n]]++;
        return 0;
    }
    long long b[500005];
    for(long long i=x;i<n;i++){
            num=-1;
        for(long long j=0;j<l;j++){
            if(b[j]==a[i]) num=j;
        }
        if(num!=-1){
            for(long long j=num;j<l;j++){
                b[j]=0;
            }
            l=num-1;
        }
        b[l]=a[i];
    }
    for(int i=0;i<l;i++){
        c[b[i]]++;
    }
    kl(x+1);
    return 0;
}
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin >> n >> m;
    for(long long i=0;i<n;i++) cin >> a[i];
    kl(0);
    for(int i=1;i<=m;i++){
        cout<<c[i]<<" ";
    }
    return 0;
}
