#include<bits/stdc++.h>
using namespace std;
long long n,m;
const int N=2e5+10;
int a[N];
int check(long long len){
    long long ans=0;
    for(int i=1;i<=n;i++){
        if(len>=a[i]){
            ans+=len-a[i];
        }else{
            return ans;
        }
    }
    return ans;
}


int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    int l=1,r=n,sum=1;

    while(l<=r){
        int mid=(l+r)/2;
        if(check(mid)<=m){
            sum=mid;
            l=mid+1;
        }else{
            r=mid-1;
        }
    }
    int s=0;
    for(int i=1;i<=n;i++){
        if(a[i]<=sum){
            s++;
        }
        else{
            cout<<s<<endl;
            return 0;
        }
    }
    cout<<s<<endl;
    return 0;
}


