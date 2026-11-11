#include<bits/stdc++.h>
using namespace std;
int n;
long long m;
long long a[500010];
bool check(int x){
    long long y=m;
    int p=0;
    for(int j=1;j<=x;j++){
        y=y-(a[x]-a[j]);
    }
    if(y>=0){
        return true;
    }
    else{
        for(int j=x+1;j<=n;j++){
            y=y+(a[j-1]-a[j-x])-(x-1)*(a[j]-a[j-1]);
            if(y>=0){
                return true;
            }
        }
    }
    return false;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    int l=1,r=n,mid=0,res;
    while(l<=r){
        mid=(l+r)/2;
        if(check(mid)){
            l=mid+1;
            res=mid;
        }
        else{
            r=mid-1;
        }
    }
    cout<<res;
    return 0;
}
