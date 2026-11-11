#include<bits/stdc++.h>
using namespace std; 
const int N=1e6;
typedef long long ll;
char a[N];
ll q[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> q[i];
		cin >> a[i];
	}
	ll l=1;ll r=n;ll ans=0;
	while(l<r){
		if(q[l]==q[r]){
			if(a[l]==a[r]){
				l++;
				r--;
			}else{
			ans+=q[r];
			a[l]=a[r];
			l++;
			r--;	
			}			
		}else if(q[l]>q[r]){
			if(a[l]==a[r]){
				q[l]-=q[r];
				r--;
			}else{
				ans+=q[r];
				q[l]=q[l]-q[r];
				r--;
			}	
		}else{
			if(a[l]==a[r]){
			q[l]-=q[r];
			l++;	
			}else{
				ans+=a[l];
				q[r]-=q[l];
			}	
		}
	}
	cout << ans;
	return 0;
}
