#include<bits/stdc++.h>
using namespace std;
bool cmp(long long &a,long long &b){
	return a<b;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n;
	long long k;
	cin>>n>>k;
	vector<long long> c(n);
	for(int i=1;i<=n;i++){
		scanf("%lld",&c[i]);
	}
	sort(c.begin(),c.end(),cmp);
	int l=1,r=n;
	while(l<r-1){
		int mid=(l+r)/2;
		long long min=1e13+1;
		for(int i=1;i<=n-mid+1;i++){
			long long sum=0;
			for(int j=i;j<i+mid-1;j++){
				sum+=(c[i+mid-1]-c[j]);
			}
			if(min>sum) min=sum;
		}
		if(min<=k){
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
