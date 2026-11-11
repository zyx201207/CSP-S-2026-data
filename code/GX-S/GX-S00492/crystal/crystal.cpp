#include<bits/stdc++.h>
using namespace std;
int n,a[1000002],ans;
struct NUM{
    long long int num;
    int k;
}h[1000002];
long long int m;
int main(){
    iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n-1;i++){
        for(int j=i;j<n-1;j++){
            if(a[j]>a[j+1]) swap(a[j],a[j+1]);
        }
    }
    int maxn=0;
    for(int i=0;i<n;i++){
        if(h[maxn].num==a[i]) h[maxn].k++;
        else{
            maxn++;
            h[maxn].num=a[i];
            h[maxn].k=1;
        }
    }
    for(int i=maxn;i>1;i--){
        long long int cost=m;
        int nans=h[i].k;
        for(int j=i-1;j>=1;j--){
            if((h[i].num-h[j].num)*h[j].k <=cost){
                cost-=(h[i].num-h[j].num)*h[j].k;
                nans+=h[j].k;
            }
            else{
                nans+=cost/(h[i].num-h[j].num);
                break;
            }
        }
        ans=max(ans,nans);
    }
    cout<<ans;
    return 0;
}
