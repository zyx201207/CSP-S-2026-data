#include<bits/stdc++.h>
using namespace std;
long long a[500005],n,m,c[500005];
int check(int x){
	long long sum=0;
	for(long long i=2;i<=x;i++){
		sum+=(i-1)*c[i]; 
	}
	if(sum<=m){
		return 1;
	}else{
		return 0;
	}
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++){
		c[i]=a[i]-a[i-1];
	}
	int l=1,r=n;
	while(l<r){
		int mid=(l+r+1)/2;
		if(check(mid)){
			l=mid;
		}else{
			r=mid-1;
		}
	}
	cout<<l;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
