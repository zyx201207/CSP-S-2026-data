#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[200005];
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	int maxx=0;
	int sum=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(m==1){
		for(int i=1;i<=n;i++) maxx=max(maxx,a[i]);
	}
	else if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				sum=a[i]&a[j];
				maxx=max(maxx,sum);
			}
		}
	}
	else if(m==n){
		int sum=a[1];
		for(int i=2;i<=n;i++){
			sum=sum&a[i];
		}
		cout<<sum<<endl;
		return 0;
	}
	else if(m==n-1){
		int sum;
		for(int i=2;i<=n;i++){
			sum=a[i-1];
			for(int j=i;j<=n;j++){
				sum=sum&a[j];
				maxx=max(maxx,sum);
			}
		}		
	}
	else if(n<=20 && m<=n){
		int k=0;
		int sum;
		for(int i=2;i<=n;i++){
			sum=a[i-1];
			for(int j=i;j<=n && sum!=a[j];j++){
				for(int k=1;k<=m;k++){
					sum=sum&a[j];
				}
			}
			maxx=max(maxx,sum);
		}
	} 
	cout<<maxx<<endl;
	return 0;
} 
