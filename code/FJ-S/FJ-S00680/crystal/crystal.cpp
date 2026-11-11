#include<bits/stdc++.h>
#define int long long
using namespace std;
const int max_n=5e5+5;
int a[max_n],n,m,maxx;
int s[max_n];
int ans=0;
int cmp(int a,int b){
	return a>b;
}
int solve(int i){
	int h=a[i];
	int lt=i,rt=n;
	while(lt<rt){
		int mid=(lt+rt+1)/2;
		int sum=s[mid]-s[i-1]-(maxx-h)*(mid-i+1);// how we need
		if(sum<=m){
			lt=mid;
		}else{
			rt=mid-1;
		}
		
	}
	return lt-i+1;
}

signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		maxx=max(maxx,a[i]);
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+(maxx-a[i]);
	}
	
	for(int i=1;i<=n;i++){
		ans=max(ans,solve(i));
	}
	
	printf("%lld",ans);
	
	return 0;
}