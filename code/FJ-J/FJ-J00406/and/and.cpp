#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	unsigned long long ans=0;
	vector<int> a;
	for(int i=0;i<n;i++){
		int t;cin>>t;
		a.push_back(t);
	}
	sort(a.begin(),a.end());
	//r(int i=0;i<n;i++)cout<<a[i]<<" ";
	for(int i=n-1;i-m>-2;i--){
		unsigned long long b=a[i];
		for(int j=0;j<m-1;j++){
			b=b&a[i-1-j];
		}
		ans=max(ans,b);
	}
	cout<<ans;
	return 0;
}
