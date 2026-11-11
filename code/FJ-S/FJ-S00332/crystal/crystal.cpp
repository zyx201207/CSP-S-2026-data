#include<bits/stdc++.h>
using namespace std;
const int MAXN=500010;
long long a[MAXN];
int n,m;
int ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	
	sort(a+1,a+n);
	
	int l=1,r=2;
	int e=m-(a[r]-a[r-1]);
	while(r<n){
		while(r<n&&e>=0){
			r++;
			e-=(r-l)*(a[r]-a[r-1]);
		}
		ans=max(ans,r-l+1-1);
		e+=(a[r]-a[l]);
		l++;
	}
	
	cout<<ans<<endl;;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
