#include <bits/stdc++.h>
using namespace std;
long long n,m,a[5000005],b[5000005],ans=1,sum;
int main(){
	freopen("crystal3.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n>5000){
		int i=1;
		while(sum+a[i]<=m){
			sum+=a[i];
			ans++;
			i++;
		}
		cout<<ans;
		return 0;
	}
	sort(a+1,a+n+1);
	for(int i=1;i<n;i++){
		if(a[i]==a[i+1]){
			ans++;
		}
		b[i]=a[i+1]-a[i];
	}
	sort(b+1,b+n+1);
	for(int j=1;j<n;j++){
		if(b[j]<=m && b[j]!=0){
			ans++;
			m=m-b[j];
			j++;
		}
	}
	if(ans==1){
		cout<<0;
	}else{
		cout<<ans;
	}
	return 0;
} 
