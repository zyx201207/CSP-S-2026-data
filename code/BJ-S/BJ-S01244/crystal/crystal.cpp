#include<iostream>
#include<algorithm>
using namespace std;
#include<stdio.h>
constexpr int N=5e5+1;
int a[N],prev_sum[N];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin.tie(nullptr) -> sync_with_stdio(false);
    int n;
    long long m;
    bool speca=true,specb=true;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(speca && a[i]!=i)speca=false;
        if(specb && i>2 && a[i]-a[i-1]!=a[i-1]-a[i-2])specb=false;
        prev_sum[i]=prev_sum[i-1]+i;
    }
    if(speca){
        int ans;
        for(int i=0;i<=N;i++)if(m<prev_sum[i]){
            ans=i-1;
            break;
        }
        cout<<ans;
        return 0;
    }else if(specb){
        m/=a[2]-a[1];
        int ans;
        for(int i=0;i<=N;i++)if(m<prev_sum[i]){
            ans=i-1;
            break;
        }
        cout<<ans;
        return 0;
    }
    sort(a+1,a+n+1);
    return 0;
}