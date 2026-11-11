#include<bits/stdc++.h>
using namespace std;
unsigned long long n,m;
long long a[500005];
long long b[500005];
long long c[500005];
int main(){
	freopen("crystal","r",stdin);
	freopen("crystal","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		cin>>a[i];
	}sort(a+1,a+1+n);
	int ans=1,tmp=0;
	for (int i=1;i<=n;i++){
		int t=1;
		for (int j=n;j>=i;j--){
			if (a[j]-a[i]>m) continue;
			if (tmp>m && (j!=n && a[j+1]!=a[j])) continue;
			for (int k=i;k<j;k++){
				tmp+=(a[j]-a[k]);
			}
			if (tmp<=m){
				t=j-i+1;break;
			}else tmp=0;
		}ans=max(t,ans);
	}cout<<ans;
	return 0;
} 
