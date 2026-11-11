#include<bits/stdc++.h>
using namespace std;
long long a[500001];
long long d[500001];
int ans[500001];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,l=0,r=0,mans=0;
	long long m;
	long long sum=0;
	cin>>n>>m;
	ans[0]=1;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	for(int i=0;i<n;i++){
		if(i>0) d[i]=a[i]-a[i-1];
		else d[0]=a[0];
	}
	while(r<n){
		r++;
		sum+=d[r]*(r-l);
		while(sum>m){
			sum-=(a[r]-a[l]);
			l++;
		}
		ans[r]=r-l+1;
		mans=max(mans,ans[r]);
	}
	cout<<mans;
	cout<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

