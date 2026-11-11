#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005];
bool yes(int x){
    long long k=0;
    for(int i=1;i<=x;i++){
        k+=a[x]-a[i];
    }
    for(int i=1;i<=n-x+1;i++){
        if(k<=m)return true;
        k+=x*(a[i+x]-a[i+x-1])-(a[i+x]-a[i]);
    }
    return false;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    int l=1,r=n;
    while(l<r){
        if(r-l<=3){
            for(int i=r;i>=l;i--){
                if(yes(i)){
                    cout<<i;
    fclose(stdin);
    fclose(stdout);
                    return 0;
                }
            }
        }
        int mid=(l+r)/2;
        if(yes(mid)){
            l=mid;
        }
        else{
            r=mid-1;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
