#include<bits/stdc++.h>
using namespace std;
int n;
long long a[200005],ans;
char b[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}
	for(int l=1,r=n;l<r;){
//		cout<<l<<' '<<r<<'\n';
		if(b[l]==b[r]){
			long long minn;
			if(a[l]<a[r]) minn=a[l];
			else minn=a[r];
			a[l]-=minn;
			a[r]-=minn;
		}
		else{
			if(a[l]<=a[r]) {
				ans+=a[l];	
//				cout<<l<<' '<<r<<'\n';			
				a[r]-=a[l];
				a[l]=0;
			} 
			if(a[l]>a[r]) {
				ans+=a[r]; 
//				cout<<l<<' '<<r<<'\n';	
				a[l]-=a[r];
				a[r]=0;
			} 
		}
		if(a[l]==0) l++;
		if(a[r]==0) r--;
	}
	cout<<ans;
	return 0;
} 
