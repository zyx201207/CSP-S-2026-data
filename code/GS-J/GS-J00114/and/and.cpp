#include<bits/stdc++.h>
using namespace std;
int a[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m,ans;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	
	//for(int i=1;i<=n;i++){
	//	cout<<a[i]<<' ';
	//}
	//cout<<'\n';
	if(m==1){
		long long maxn=0;
		for(int i=1;i<=n+1;i++){
			if(a[i]>maxn){
				maxn=a[i];
				
			}
		}
		ans=maxn;
	}
	if(m==n){
		long long x=a[1];
		for(int i=2;i<=n;i++){
			x&=a[i];
		}
		ans=x;
	}
	if(m==2){
		long long maxn=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(j!=i){
					long long x=a[i]&a[j];
					maxn=max(x,maxn);
				}
			}
		}
		ans=maxn;
	}
	if(m==n-1){
		long long maxn=0;
		for(int i=1;i<=n;i++){
			long long x=a[1];
			for(int j=2;j<=n;j++){
				if(j!=i){
					x&=a[j];
					
				}
				
			}
			maxn=max(x,maxn);
		}
		ans=maxn;
	}
	cout<<ans;
	return 0;
}
