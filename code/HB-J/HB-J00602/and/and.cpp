#include<bits/stdc++.h>
using namespace std;
long long n,m,maxn=-9999999999,t[1000005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","r",stdout);
	cin>>n>>m;
	for(long long i=0;i<n;i++){
		cin>>t[i];
	}
	if(m==1){
		for(int i=0;i<n;i++){
			maxn=max(maxn,t[i]);
		}
	}else if(m==n){
		for(int i=0;i<n;i++){
			if(i==0){
				maxn+=t[i];
				continue;
			}
			maxn=maxn & t[i];
		}
	}else if(m==2){
		for(long long i=0;i<m;i++){
			for(long long j=1;j<=m-i;j++){
				maxn=max (maxn,t[i] & t[i+j]);
			}
		}
	}
	cout<<maxn;
	return 0;
}
