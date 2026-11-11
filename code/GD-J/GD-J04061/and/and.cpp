#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;cin>>n>>m;
	vector<int> a(n);
	for(int i=0;i<n;i++) cin>>a[i];
	sort(a.begin(),a.end());
	
	int tmp=n-1,ans;
	for(int i=0;i<m;i++){
		if(i==0) ans=a[tmp];
		else ans=ans&a[tmp];
		tmp--;
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
