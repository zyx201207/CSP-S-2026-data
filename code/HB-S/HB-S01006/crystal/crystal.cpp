#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
long long n,m;
long long l,r,mid;
const int N=5e5+7;
long long a[N];
bool cmp(int a,int b){
    return a<b;
}
long long ans,k;
long long sum;
bool check(long long x){
    sum=0;
    for(int i=1;i<=n;i++){
        if(a[i]<x) sum+=(x-a[i]);
    }
    return sum<=m;
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
    sort(a+1,a+n+1,cmp);
    l=1,r=n;
    while(l<=r){
        mid=l+(r-l)/2;
        k=0;
        if(check(a[mid])){
            for(int i=1;i<=n;i++){
                if(a[i]<=a[mid]) k++;
            }
            l=mid+1;
            ans=k;
        }
        else r=mid-1;
    }
    cout<<ans;
    return 0;
}
