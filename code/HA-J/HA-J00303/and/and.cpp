#include<bits/stdc++.h>
using namespace std;
long long aa[200005],ans[200005];
int a[200005][32];
int t[32];
long long n,m;
int mp=31;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>aa[i];
	}
	for(int i=1;i<=n;i++){
		int p=30;
		while(aa[i]){
			a[i][p]=aa[i]%2;
			if(aa[i]%2==1)t[p]++;
			p--;
			aa[i]/=2;
		}
		mp=min(mp,p);
	}
	mp++;
	for(int i=mp;i<=30;i++){
		if(t[i]<m)for(int j=1;j<=n;j++){
			a[j][i]=0;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=mp;j<=30;j++){
			ans[i]+=pow(2,30-j)*a[i][j];
		}
	}
	sort(ans+1,ans+n+1);
	int co=ans[n];
	for(int i=n-1;i>=n-m+1;i--){
		co=co&ans[i];
	}
	cout<<co;
	return 0;
}