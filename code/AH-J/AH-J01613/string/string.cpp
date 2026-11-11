#include<bits/stdc++.h>
using namespace std;
long long a[200005];
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); 
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	int l=1,r=n;
	long long ans=0;
	while(l<r){
		if(c[l]==c[r]){
			if(a[l]==a[r]){
				l++;
				r--;
			}
			else if(a[l]>a[r]){
				a[l]-=a[r];
				r--;
			}
			else if(a[l]<a[r]){
				a[r]-=a[l];
				l++;
			}
		}
		else{
			if(a[l]==a[r]){
				ans+=a[l];
				l++;
				r--;
			}
			else if(a[l]>a[r]){
				a[l]-=a[r];
				ans+=a[r];
				r--;
			}
			else if(a[l]<a[r]){
				a[r]-=a[l];
				ans+=a[l];
				l++; 
			}
		}
	}
	cout<<ans;
	return 0;
} 
