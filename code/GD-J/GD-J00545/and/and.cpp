#include<bits/stdc++.h>
using namespace std;
long long n,m,a[300005],b[300005],mx=0;
void dfs(long long k,long long h,long long t){
	t=t&b[k-1];
	if(k>m){
		mx=max(mx,t);
		return;
	}
	for(long long i=h;i>=1;i--){
		if(a[i]<=mx){
			continue;
		}
		b[k]=a[i];
		if(k==1){
			t=b[k];
		}
		if(t<=mx){
			continue;
		}
		dfs(k+1,i-1,t);
	}
	return;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(1,n,0);
	cout<<mx;
	fclose(stdin);
	fclose(stdout);
	
	return 0;
} 
