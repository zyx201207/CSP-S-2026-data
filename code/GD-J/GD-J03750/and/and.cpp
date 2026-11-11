#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(m==1){
		cout<<a[n];
		return 0;
	}
	else if(m==n){
		for(int i=2;i<=n;i++){
			a[i]=(a[i]&a[i-1]);
		}
		cout<<a[n];
		return 0;
	}
	else if(m==2){
		int maxx=INT_MIN;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				int t=(a[i]&a[j]);
				maxx=max(maxx,t);
			}
		}
		cout<<maxx;
		return 0;
	}
	else if(m==n-1){
		int maxx=INT_MIN;
		int t=2e21-1;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(j==i){
					continue;
				}
				t=(t&a[j]);
			}
			maxx=max(maxx,t);
		}
		cout<<maxx;
		return 0;
	}
	else if(a[n]<4){
		int maxx=a[n];
		for(int i=n;i>=n-m+1;i--){
			maxx=(maxx&a[n]);
		}
		cout<<maxx;
		return 0;
	}
	else{
		cout<<a[n-m+1];
		return 0;
	}
	return 0;
}
