#include <bits/stdc++.h>
using namespace std;
const int N=5e5+5;
long long arr[N],diff[N],sum[N],num[N];
int cur;
bool cmp(long long m,long long l){
    return sum[l]-sum[cur]-diff[cur]*(cur-l)<=m;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n;
    long long m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    for(int i=1;i<=n;i++){
        num[i]=i;
    }
    sort(arr+1,arr+n+1);
    for(int i=1;i<n;i++){
        diff[i]=arr[i+1]-arr[i];
    }
    for(int i=n;i>=1;i--){
        diff[i]+=diff[i+1];
        sum[i]=diff[i];
    }
    for(int i=n;i>=1;i--){
        sum[i]+=sum[i+1];
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        cur=i;
        int pos=upper_bound(num+1,num+i+1,m,cmp)-num;
        ans=max(ans,i-pos+1);
    }
    cout<<ans;
    return 0;
}
