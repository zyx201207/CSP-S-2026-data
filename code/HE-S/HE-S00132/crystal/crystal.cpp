#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n;
long long m,a[N],mx=-1e18,sum,rans=-1e18,ans[N],sm[N];
bool dc=true;
int cnt;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sm[i]=sm[i-1]+a[i];
	}
	int d=abs(a[2]-a[1]);
	for(int i=2;i<=n;i++) if(a[i]-a[i-1]!=d) dc=false;
	if(dc){
		cout<<m/d;
		return 0;
	}
	sort(a+1,a+1+n);
	for(int l=1;l<=n;l++){
		for(int r=n;r>l;r--){
			sum=sm[r]-sm[l-1];
			mx=a[r];
			sum=mx*(r-l+1)-sum;
			if(sum<=m) ans[++cnt]=r-l+1;
		}
	}
	for(int i=1;i<=cnt;i++) rans=max(ans[i],rans);
	cout<<rans;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
