#include<bits/stdc++.h>
using namespace std;
long long n;
long long m;
long long a[500050];
long long aa[500050];
long long b[500050];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=n;i>=1;i--){
		long long mid=m,idx=a[i-1];
		for(int j=1;j<=n;j++){
			aa[j]=a[j];
		}
		for(int j=i-1;j>=1;j--){
			if(mid>=idx-aa[j]){
				mid-=idx-aa[j];
				aa[j]=idx;
			}
			else{
				break;
			}
		}
		for(int j=1;j<=n;j++){
			if(aa[j]==idx){
				b[i]++;
			}
		}
	}
	long long ans=-1;
	for(int i=1;i<=n;i++){
		ans=max(ans,b[i]);
	}
	cout<<ans<<'\n';
	return 0;
}
