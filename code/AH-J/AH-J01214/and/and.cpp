#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[200005];
long long maxx=0;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) {
		cin>>a[i];
		maxx=max(maxx,a[i]);
	}
    if(m==1) {
		cout<<maxx;
	}
	else if(m==n){
		long long t=a[1];
		for(int i=2;i<=n;i++) t=t&a[i];
		cout<<t;
	}
	else if(m==2){
		maxx=0;
		for(int i=1;i<=n-1;i++){
			for(int j=i+1;j<=n;j++){
				if(i!=j){
					maxx=max(maxx,a[i]&a[j]);
				}
			}
		}
		cout<<maxx;
	}
	else {
		sort(a+1,a+n+1);
		long long x=a[n];
		for(int i=n-1;i>=n-m+1;i--){
				x=x&a[i];
			}
		cout<<x;
	}
}
