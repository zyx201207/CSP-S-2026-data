/*
5 3
1 2 4 7 8
*/
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+12;
int a[N],diff[N];
int n,m;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		diff[i]=a[i]-a[i-1];
	}
	int sum=0,maxn=-1;
	int l=1,r=1;
	while(l<=n&&r<=n){
		if(sum+diff[r]*(r-l)<=m){
			sum+=diff[r]*(r-l);
			maxn=max(maxn,r-l+1);
			r++;
		}
		else{
			sum-=(a[r-1]-a[l]);
			l++;
		}
	}
	cout<<maxn;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
/*
5 8
-3 -1 2 2 7
*/
//wo ceng jing jianguo hen duo tian cai , dan ta men dou guan wo jiao qu 
