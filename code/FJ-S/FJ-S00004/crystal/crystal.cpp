#include<bits/stdc++.h>
using namespace std;namespace Sol{long long n,m,i,j,k,s,t,a[500100];
void M(){for(cin>>n>>m;i^n;cin>>a[++i]);for(i=0,sort(a+1,a+n+1);i^n;k<i-j?k=i-j:0)for(s+=t=a[++i];t*(i-j)-s>m;s-=a[++j]);cout<<k;}
}int main(){return freopen("crystal.in","r",stdin),freopen("crystal.out","w",stdout),ios::sync_with_stdio(0),cin.tie(nullptr),Sol::M(),0;}