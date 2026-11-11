#include<bits/stdc++.h>
using namespace std;
long long a[500001];
long long b[500001];
long long c[500001];
int n;
long long m;
int f(int x){
	for(int r=x;r<=n;r++){
		if((c[r]-c[r-x+1]-(r-x)*(a[r]-a[r-x+1]))<=m)return 1;
	}
	return 0;
}
int main(){
	
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
	 	b[i]=a[i]-a[i-1];
	}
	for(int i=2;i<=n;i++){
		c[i]=c[i-1]+(i-1)*b[i];
	}
	int l=1,r=n;
	while(l<=r){
		int mid=(l+r)/2;
		if(f(mid)){
			l=mid+1;
		}
		else{
			r=mid-1;
		}
	}
	cout<<r;
}
