#include<bits/stdc++.h>
using namespace std;
long long a[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	int ans=0;
	int n_m;
	int now=0;
	int l=0;
	for(int r=0;r<n;r++){
		n_m+=now*(a[r]-a[r-1]);
		while(n_m>m){
			n_m-=(a[r]-a[l]);
			l++;
		}
		now=r-l+1;
		ans=max(ans,now);
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
