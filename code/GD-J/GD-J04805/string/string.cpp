#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+5;
string b[N];
ll a[N],n,ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout); 
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}
	ll l=1,r=n;
	while(l<r){
		if(b[l]!=b[r]){
			if(a[l]<a[r]){
				ans+=a[l];
				a[r]-=a[l];
				l++;
			}
			else if(a[l]==a[r]){
				ans+=a[l];
				l++;
				r--;
			}
			else{
				ans+=a[r];
				a[l]-=a[r];
				r--;
			}
		}
		else{
			if(a[l]<a[r]){
				a[r]-=a[l];
				l++;
			}
			else if(a[l]==a[r]){
				l++;
				r--;
			}
			else{
				a[l]-=a[r];
				r--;
			}
		}
	}
	cout<<ans;
	return 0;
} 
