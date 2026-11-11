#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n;
long long m,Max;
long long s[N],qzh[N];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>s[i];
    }
    sort(s+1,s+1+n);
    for(int i=1;i<=n;i++){
        qzh[i]=qzh[i-1]+s[i];
    }
    int l=1;
    for(int r=1;r<=n;r++){
        while(s[r]*(r-l+1)-qzh[r]+qzh[l-1]>m){
            l++;
        }
        Max=max(Max,(long long)r-l+1ll);
    }
    cout<<Max;
    return 0;
}
