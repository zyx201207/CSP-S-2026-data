#include<bits/stdc++.h>
using namespace std;
long long n,m,a[1000005],b[10000005],x;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	for(int j=1;j<=m;++j){
		long long maxn=a[1];
		for(int i=1;i<=n;++i){
			maxn=max(maxn,a[i]);
		}
		b[x++]=maxn;
		for(int i=1;i<=n;++i){
			if(a[i]==maxn){
				a[i]=0;
			}
		}
	}
	long long ans=b[0]&b[1];
	for(int i=0;i<x;++i){
		ans=ans & b[i];
	}
	cout<<ans;
	return 0;
} 
