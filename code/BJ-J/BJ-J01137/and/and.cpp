#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
long long n,m,a[1000001];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(long long i=0;i<n;i++){
		cin>>a[i];
    }
    sort(a,a+n);
    if(m==1){
		cout<<a[n-1];
		return 0;
    }
    if(m==2){
		long long _max = INT_MIN;
		for(long long i=0;i<n;i++ ){
			for(long long j=0;j<n;j++){
				if(i==j)continue;
				long long k=a[i]|a[j];
				if(k>_max)_max=k;
			}
		}
		cout<<_max;
		return 0;
    }
    if(m==n){
		int k=1;
		for(int i=0;i<n;i++){
			k=k|a[i];
		}
		cout<<k;
    }
    return 0;
}
