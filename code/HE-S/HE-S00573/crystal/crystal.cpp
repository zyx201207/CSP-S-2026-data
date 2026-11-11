#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int N=5e5+10;
LL n, a[N], m;

int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	cin>>n>>m;
	for(int i=1; i<=n; i++){
		cin>>a[i];
	}
	
	sort(a+1, a+1+n);
	int l=0, sum=0, res=0;
	for(int r=1; r<=n; r++){
		sum+=(a[r]-a[r-1])*(r-l);
		while(sum>m){
			sum-=a[r]-a[l];
			l++;
		}
		res=max(res, r-l+1);
	}
	
	cout<<res;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 

