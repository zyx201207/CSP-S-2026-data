#include<iostream>
#include<cstdio>
using namespace std;
int n,m;
long long a[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(m==1){
		long long maxn=0;
		for(int i=1;i<=n;i++) maxn=max(maxn,a[i]);
		cout<<maxn;
		return 0;
	}
	if(m==2){
		long long maxn=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				maxn=max(maxn,a[i]&a[j]);
			}
		}
		cout<<maxn;
		return 0;
	}
	if(m==n){
		long long maxn=a[1];
		for(int i=2;i<=n;i++) maxn=maxn&a[i];
		cout<<maxn;
		return 0;
	}
	if(m==n-1){
		long long maxn=a[1];
		for(int i=2;i<=n;i++) maxn=maxn&a[i];
		long long mmaxn=0;
		for(int i=1;i<=n;i++){
			mmaxn=max(mmaxn,maxn&a[i]);
		}
		cout<<mmaxn;
		return 0;
	}
	long long maxn=0;
	for(int i=1;i<=n;i++) maxn=max(maxn,a[i]);
	cout<<maxn;
	return 0;
}
