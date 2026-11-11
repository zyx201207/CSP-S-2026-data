#include<bits/stdc++.h>
using namespace std;
int n,a[200009],s;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>s;
	int mi=INT_MIN;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		mi=max(mi,a[i]);
	}
	if(s==1){
		cout<<mi;
		return 0;
	}
	if(s==2){
		int ma=INT_MIN;
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				ma=max(ma,a[i]&a[j]);
			}
		}
		cout<<ma;
		return 0;
	} 
	if(s==n){
		int ans=a[1];
		for(int i=2;i<=n;i++){
			ans=ans&a[i];
		}
		cout<<ans;
		return 0;
	}
	sort(a+1,a+1+n);
	cout<<a[n-s+1];
	return 0;
}
