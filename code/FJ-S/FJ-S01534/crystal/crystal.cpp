#include<bits/stdc++.h>
using namespace std;
long long a[500005];
long long d(int l,int r){
	long long s=0;
	for(int i=l;i<r;i++) s+=(a[r]-a[i]);
	return s;
}
long long pd(long long n){
	long long j=a[1]-a[0];
	for(long long i=1;i<n-1;i++) if(a[i+1]-a[i]!=j) return 0;
	if(j==1&&a[0]==1) return 0;
	else return j;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++) cin>>a[i];
	long long p=pd(n);
	if(p){
		if(p!=0) m/=p;
		long long sum=0,i=0;
		while(sum<=n&&sum<=m){
			i++;
			sum+=i;
		}
		if(sum>m) cout<<i;
		else cout<<i+1;
		return 0;
	}
	sort(a,a+n);
	long long sum=1;
	for(int i=2;i<=n;i++){
		for(int j=0;j<n-i;j++){
			if(d(j,j+i-1)<=m){
				sum=i;
				break;
			}
		}
	}
	cout<<sum;
	fclose(stdin);
	fclose(stdout);
	return 0;
}