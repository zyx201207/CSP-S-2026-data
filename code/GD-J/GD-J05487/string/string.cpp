#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,cnt=0;
	string s;
	cin>>n;
	int a[n];
	char c[n];
	for(int i=0;i<n;i++){
		cin>>a[i]>>c[i];
		cnt+=a[i];
	}
//	bool ok=1;
	int sum=0;
//	for(int i=0;i<n-1;i++){
//		if(c[i]!=c[i+1]){
//			ok=0;
//		}
//	}
//	if(ok=1){
//		cout<<0;
//		return 0;
//	}
	int l=0,r=n-1;
	for(int i=0;i<n;i++){
		
		if(c[l]!=c[r]&&l<r){
			if(a[l]>a[r]){
				sum+=a[r];
				a[l]-=a[r];
				r--;
			}else if(a[l]==a[r]){
				sum+=a[r];
				l++;
				r--;
			}else if(a[l]<a[r]){
				sum+=a[l];
				a[r]-=a[l];
				l++;
			}
			
		}
		
	}
	
	cout<<sum;
	return 0;
}
