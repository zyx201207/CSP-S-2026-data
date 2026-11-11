#include<bits/stdc++.h>
using namespace std;long long n,m,a[100000],i=0,S=9223372036854775807,M=0,N=9223372036854775807,_=0;int main(){freopen("and.in","r",stdin);freopen("and.out","w",stdout);cin>>n>>m;for(;i<n;i++){cin>>a[i];N=min(a[i],N);M=max(a[i],M);}for(i=0;i<n;i++){if(a[i]==S&&_<1)_++;else S&=a[i];}if(n==m)cout<<(S&m);if(m==n-1)cout<<S;if(m==1)cout<<M;return 0;}
