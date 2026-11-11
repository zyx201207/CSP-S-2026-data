#include<bits/stdc++.h>
using namespace std;
int n,m,a[1000005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(m==1){
		sort(a,a+n);
		cout<<a[n-1];
		return 0;
	}else{
		int ans=0;
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				ans=max(ans,a[i]&a[j]);
			}
		}
		cout<<ans;
		return 0;
	}
	sort(a,a+n);
		cout<<a[n-1];
	return 0;
}
