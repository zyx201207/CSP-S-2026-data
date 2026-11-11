#include<bits/stdc++.h>
using namespace std;long long n,a[100000],i=0,s=0,S,A=0,j;int main(){freopen("string.in","r",stdin);freopen("string.out","w",stdout);char b[100000];string x;cin>>n;for(;i<n;i++){cin>>a[i]>>b[i];}for(i=0;i<n;i++)for(j=0;j<a[i];j++)x+=b[i];for(S=x.size()/2;S<x.size();S++)if(x[S]!=x[x.size()-1-S])A++;cout<<A;return 0;}
