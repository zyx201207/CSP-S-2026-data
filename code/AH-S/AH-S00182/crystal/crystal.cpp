#include<bits/stdc++.h>
using namespace std;
long long a[500010];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n;
	long long m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int ans=1;
	for(int i=n-1;i>=1;i--){
		if(a[n]-a[i]<=m){
			m-=a[n]-a[i];
			a[i]=a[n];
			ans++;
		}else{
			break;
		}
	}
	cout<<ans;
	return 0;
}
