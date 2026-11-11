#include <bits/stdc++.h>
using namespace std;
long long n,m,a[1000005],maxx=0;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(m==1){
		for(int i=1;i<=n;i++) if(a[i]>maxx) maxx=a[i];
		cout<<maxx;
	}
	if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=n;j>i;j--){
				if(a[i]&a[j]>maxx) maxx=a[i]&a[j];
			}
		}
		cout<<maxx;
	}
	if(m==3){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n&&j!=i;j++){
				for(int k=1;k<=n&&k!=j&&k!=i;k++){
					if(a[i]&a[j]&a[k]>maxx) maxx=a[i]&a[j]&a[k];
				}
			}
		}
		cout<<maxx;
	}
	if(m==n){
		maxx=a[1];
		for(int i=2;i<=n;i++) maxx=maxx&a[i];
		cout<<maxx;
	}
	cout<<sb(m,1);
	return 0;
}

