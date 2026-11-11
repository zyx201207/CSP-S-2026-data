#include<bits/stdc++.h>
using namespace std;
long long n,a[200010],c[200010];
char b[200010];
long long s,u,r,l,o;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(long long i=1;i<=n;i++){
        cin>>a[i]>>b[i];
        s+=a[i];
        c[i]=s;
    }
    u=s/2,r=n,l=1LL,o=0LL;
    char z=b[1],y=b[n];
    for(long long i=1;i<=u;i++){
        if(i>c[l]){
            l++;
            z=b[l];
        }
        if(s<=c[r-1]){
            r--;
            y=b[r];
        }
        if(z!=y){
            o++;
        }
        s--;
    }
    cout<<o;
    return 0;
}
