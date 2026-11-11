#include<bits/stdc++.h>
using namespace std;
long long n,m,ans=1,f;
long long erg[1000000];
bool cmp(long long x,long long y){
    return x>y;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>erg[i];
        if(erg[i]!=i)f=1;
    }
    sort(erg+1,erg+n+1,cmp);
    if(erg[1]-erg[2]>1){

    }
    long long bse=erg[1];
    for(int i=1;i<=n;i++){
        if(m-i>=0){
            m-=i;
            ans++;
        }
    }
    if(ans>n){
            cout<<n;
            return 0;
    }
    cout<<ans;
    return 0;
}
