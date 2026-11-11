#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],ans,sum[500005],b[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			if(a[i]==a[j]){
				sum[i]++;
			}
		}
	}
	b[1]=0;
	for(int i=2;i<=n;i++){
		b[i]=b[i-1]+(i-1)*(a[i]-a[i-1]);
	}
	for(int i=1;i<=n;i++){
		if(b[i]<=m){
			ans=i+sum[i];
		}
	}
	cout<<ans;
	return 0;
}

