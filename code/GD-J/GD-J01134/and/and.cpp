#include<bits/stdc++.h>
using namespace std;
long long n,m,a[10000000],maxn=-1;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout); 
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		for(long long i=1;i<=n;i++){
			maxn=max(maxn,a[i]); 
		}
		cout<<maxn;
	}
	
	else if(m==2){
		for(long long i=1;i<=n;i++){
			for(long long j=i+1;j<=n;j++){
				maxn=max(maxn,a[i]&a[j]);
			}
		}
		cout<<maxn;
	}
	
	else if(m==n){
		maxn=a[1];
		for(long long i=2;i<=n;i++){
			maxn&=a[i];
		}
		cout<<maxn;
		
	} else{
		cout<<0;
	}
	return 0;
}
