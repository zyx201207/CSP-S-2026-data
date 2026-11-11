#include <bits/stdc++.h>
using namespace std;
int a[int(2*1e5+10)],n;

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int m;
	cin>>n>>m;
	for (int i=0;i<n;i++){
		cin>>a[i];

	}
	sort(a,a+n);
	int ans=0;
	if(m==1) ans=a[0];
	if(m==n){
		ans=a[0];
		for(int i=0;i<n;i++){
			ans=ans&a[i];
		}
	}
	else if(m==2){
		for(int i=0;i<n;i++){
			for(int j=i;j<n;j++){
				if(i==j) continue;
				ans=max(ans,a[i]&a[j]);
			}
		}
	}
	else{
		ans=a[0];
		for(int i=0;i<m;i++){
			ans=ans&a[i];
		}
	}
	cout<<ans;
	return 0;
}
