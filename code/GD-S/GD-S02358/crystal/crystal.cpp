#include<bits/stdc++.h>
using namespace std;
int n;
long long m;
long long a[500010];
long long b[500010];
int mid;
int ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	/*for(int i=1;i<=n;i++){
		cout<<a[i]<<' ';
	}*/
	mid=n/2+n%2;
	for(int i=1;i<=n;i++){
		if(a[mid]>a[i]){
			b[i]=a[mid]-a[i];
		}
		else{
			b[i]=a[i]-a[mid];
		}
	}
	int r=mid;
	while(m>0,r>=1){
		if(b[r]!=0){
			b[r]--;
			m--;
		}
		else r--;
	}
	r=mid;
	while(m>0){
		if(m>=b[r+1]*r){
			m-=b[r+1]*r;
		}
		else{
			break;
		}
		r++;
	}
	for(int i=1;i<=n;i++){
		if(b[i]==0){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
