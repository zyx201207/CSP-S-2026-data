#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,maxx=0;
const int maxn=2e5+10;
int a[maxn],b[maxn];
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(n<=20){
		maxx=a[n];
		for(int i=n;i>=n-m+1;i--){
			maxx=maxx&a[i];
		}
	}
	else if(n<=2000){
		if(m==1)maxx=a[n];
		else if(m==n){
			maxx=a[1];
			for(int i=1;i<=n;i++){
				maxx=maxx&a[i];
			}
		}
		else{
			for(int i=1;i<n;i++){
				for(int j=i+1;j<=n;j++){
					maxx=max(maxx,a[i]&a[j]);
				}
			}
		} 
	}
	else{
		bool f=0,t=0;
		for(int i=1;i<=n;i++){
			if(a[i+1]!=a[i]*2+1){
				f=1;
			}
			if(a[i]!=i-1)t=1;
		}
		if(f==0){
			maxx=a[n-m+1];
		}
	}
	cout<<maxx;
	
	
	
	return 0;
} 
