#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005];
bool check(int mid,int num,int m){
    if(m-(mid-num)>=0){
        return true;
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
    sort(a+1,a+n+1);
    int cnt,maxn=INT_MIN,v;
    for(int i=2;i<=n;i++){
        v=m,cnt=1;
        for(int j=1;j<i;j++){
            if(check(a[i],a[j],v)==true){
                v-=(a[i]-a[j]),cnt++;
            }
        }
        maxn=max(maxn,cnt);
    }
    cout<<maxn;
    return 0;
}
