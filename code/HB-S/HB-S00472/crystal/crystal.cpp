#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,m,maxn;
long long a[N];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++) cin>>a[i];
    sort(a,a+n);
    for(int i=0;i<n;i++){
        int k=0;
        for(int j=i;j>=0;j--){
            k+=(a[i]-a[j]);
            if(k>m) break;
            maxn=max(maxn,i-j+1);
        }
    }
    cout<<maxn;
}
