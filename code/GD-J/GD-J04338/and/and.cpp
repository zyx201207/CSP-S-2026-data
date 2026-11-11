#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	vector<int> a(n);
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int ans=-0x3f3f3f3f;
	for(int i=0;i<n-m+1;i++){
		int cnt=a[i];
		for(int j=i+1;j<i+m;j++){
			cnt^=a[j];
		}
		if(cnt>ans){
			ans=cnt;
		}
	}
	cout<<ans<<'\n';
	return 0;
}
