#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	int m,n,z;
	int ans=0;
	cin>>n>>m;
	vector<int> a(n);
	
	
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	
	sort(a.begin(),a.end());
	z=a[n/2];
	
	for(int i=0;i<n;i++){	
	if(a[i]>z){
			a[i]=a[i]-z;
		}else{
			a[i]=z-a[i];
		}
	}
	
	sort(a.begin(),a.end());
	
	while(m>=1){
		m=m-a[ans];
		ans++;
	}
	
	cout<<ans<<endl;
	return 0;
}