#include<iostream>
#include<vector>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m,ans=-1,p=0;
	cin>>n>>m;
	long long a[n+1];
	for(long long i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			ans=max(ans,a[i]&a[j]);
		}
	}
	cout<<ans;
	return 0;
}
