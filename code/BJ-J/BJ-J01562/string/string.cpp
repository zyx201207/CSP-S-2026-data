#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+5;
int n,a[N];
char c[N],p;
signed main(){
    //freopen("string.in","r",stdin);
    //freopen("string.out","w",stdout);
    long long n_=0;
    cin>>n;
    int v=0;
    for(int i=0;i<n;i++){
        cin>>a[i]>>c[i];
        n_+=a[i]/2;
        if(p!=c[i]) v=1;
        p=c[i];
    }
    if(n==1||v==0) return cout<<0<<endl,0;
    cout<<n_<<endl;
    return 0;
}
