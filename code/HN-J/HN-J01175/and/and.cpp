#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		long long maxx=0;
		for(int i=1;i<=n;i++){
			maxx=max(maxx,a[i]);
		}
		cout<<maxx;
		return 0;
	}
	if(m==n){
		long long ans=a[1];
		for(int i=2;i<=n;i++){
			ans&=a[i];
		}
		cout<<ans;
		return 0;
	}
	if(m==2){
		long long maxx=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i!=j)maxx=max(maxx,a[i]&a[j]);
			}
		}
		cout<<maxx;
		return 0;
	}
	if(m==n-1){
		long long maxx=0;
		long long f=a[2];
		for(int i=2;i<=n;i++){
			f&=a[i];
		}
		maxx=f;
		for(int i=2;i<=n;i++){
		    f=a[1];
			for(int j=1;j<=n;j++){
				if(i==j){
					continue;
				}
				f&=a[j];
			}
			maxx=max(maxx,f);
		}
		cout<<maxx;
		return 0;
	}
	return 0;
}
