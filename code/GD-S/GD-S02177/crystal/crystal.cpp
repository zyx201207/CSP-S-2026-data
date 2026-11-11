#include<bits/stdc++.h>
using namespace std;
const int M = 5e5+10;
int n,a[M],cf[M],ans,mx,tans;
long long m;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin >> n >> m;
    for(int i=0;i<n;i++){
        cin >> a[i];
    }cf[0] = 0;
    for(int i=1;i<n;i++){
        cf[i] = a[i]-a[i-1];
        ans=0;tans=0;
        for(int k=i;k>=1;--k){
        	if(ans>=m) break;
            ans+=(ans+cf[k]);
            tans++;
        }
		mx=max(mx,tans);
    }cout << mx+1;
}
