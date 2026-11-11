#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005];
long long maxx=-1;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	if(m==1){
		cout<<a[n];
	}
	else if(n==m){
		int ans=a[1];
		for(int i=2;i<=n;i++){
			ans&=a[i];
		}
		cout<<ans;
	}
	if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(maxx<a[i]&a[j]){
					maxx=a[i]&a[j];
				}
			}
		}
		cout<<maxx;
	}
	return 0;
} 
