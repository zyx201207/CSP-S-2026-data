#include <bits/stdc++.h>
using namespace std;
const int N = 1e8+5;
int a[N];
int n,k;
int main(){
	freopen("and,in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(k==1){
		sort(a+1,a+1+n);
		cout<<a[n];
		return 0;
	} 
	else if(k==n){
		int ans=a[1];
		for(int i=2;i<=n;i++){
			ans=ans&a[i];
		}
		cout<<ans;
		return 0;
	}else if(k==2){
		int maxi=-1;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				maxi=max(maxi,(a[i]&a[j]));
			}
		}
		cout<<maxi;
		return 0;
	}
	else if(k==n-1){
		int maxi=-1;int ans=a[1];
		for(int i=2;i<=n;i++){
			for(int j=2;j<=n;j++){
				if(j==i) j++;
				ans=ans&a[j];
			}
			maxi=max(maxi,ans);
		}
		cout<<maxi;
		return 0;
	} 
	return 0;
}
