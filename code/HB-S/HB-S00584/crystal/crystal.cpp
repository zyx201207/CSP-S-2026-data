#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=5e5+10;
int n,m;
int a[maxn];
void pp(){
    for(int i=1;i<=n;i++){
        cout<<a[i]<<' ';
    }
}
bool chek(int num){
    for(int i=num;i<=n;i++){
        int val=m;
        for(int j=i-1;j>=i-num+1;j--){
            val-=(a[i]-a[j]);
            //cout<<a[j]<<' ';
        }
        if(val>=0) return true;
    }
    return false;
}
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++) {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    int l=1,r=n;
    int mid=(l+r)/2;
    while(l<r-1){
        //cout<<"l:"<<l<<" r:"<<r<<" mid:"<<mid<<endl;
        if(chek(mid)) l=mid;
        else {
            r=mid;
        }
        mid=(l+r)/2;
    }
    cout<<mid;
    return 0;
}
// 5 5 1 2 4 8 9
// 5 8 -3 -1 2 2 7
