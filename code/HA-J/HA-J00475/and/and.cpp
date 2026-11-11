#include<bits/stdc++.h>
using namespace std;
long long n,m;
int maxx;
int a[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	if(n==m){
		maxx=a[1]&a[2];
		for(long long i=2;i<n;i++){
			maxx=maxx&a[i+1];
		}	
		cout<<maxx;
	}else if(m==1){
		cout<<a[n];
	}else if(m==2){
		for(long long i=1;i<n;i++){
			for(long long j=i+1;j<=n;j++){
				maxx=max(maxx,a[i]&a[j]);
			}
		}
		cout<<maxx;
	}else if(m==3){
		for(long long i=1;i<n-1;i++){
			for(long long j=i+1;j<n;j++){
				for(long long k=j+1;k<=n;k++){
					maxx=max(maxx,a[i]&a[j]&a[k]);
				}
			}
		}
		cout<<maxx;
	}else if(m==4){
		for(long long i=1;i<n-1-1;i++){
			for(long long j=i+1;j<n-1;j++){
				for(long long k=j+1;k<n;k++){
					for(long long k1=k+1;k1<=n;k1++){
						maxx=max(maxx,a[i]&a[j]&a[k]&a[k1]);
					}
				}
			}
		}
		cout<<maxx;
	}else{
		cout<<a[n];
	}
	return 0;
}
