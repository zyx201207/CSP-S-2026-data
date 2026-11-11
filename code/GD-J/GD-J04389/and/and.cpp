#include<bits/stdc++.h>
using namespace std;
bool cmp(long long a,long long b){
	return a>b;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m,a[200001],ans=1;
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		cout<<a[1];
		return 0;
	}
	if(m==2){
		for(long long i=1;i<=n;i++){
			for(long long j=i+1;j<=n;j++){
				ans=max(ans,a[i]&a[j]);
			}
		}
		cout<<ans;
		return 0;
	}
	sort(a+1,a+n+1,cmp);
	ans=a[1];
	for(long long i=2;i<=m;i++){
		ans=ans&a[i];
	}
	cout<<ans;
	return 0;
}
