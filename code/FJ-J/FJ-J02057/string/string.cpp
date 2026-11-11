#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[200005];
char c[200005];
ll ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	int l=1,r=n;
	while(l<r){
		if(c[l]!=c[r]){
			if(a[l]>=a[r]){
				a[l]-=a[r];
				ans+=a[r];
				r--;
			}else{
				a[r]-=a[l];
				ans+=a[l];
				l++;
			}
		}else{
			if(a[l]>=a[r]){
				a[l]-=a[r];
				ans+=0;
				r--;
			}else{
				a[r]-=a[l];
				ans+=0;
				l++;
			}
		}
		
	}
	cout<<ans;
	return 0;
}
