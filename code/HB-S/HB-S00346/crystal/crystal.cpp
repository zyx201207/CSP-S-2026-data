#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],b[500005],k=0,l,v,z,op=0;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    v=m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=2;i<=n;i++){
        for(int j=i-1;j>=1;j--){
            if(a[i]-a[j]<=v){
                b[i]++;
                v-=a[i]-a[j];
            }else break;
        }
        v=m;
    }
    b[1]=0;
    for(int i=1;i<=n;i++){
        if(b[i]>=k){
            k=b[i];
            l=i;
        }
    }
    z=l-1;
    while(m>=0){
        m-=a[l]-a[z];
        op++;
        z--;
    }
    cout<<op;
}
