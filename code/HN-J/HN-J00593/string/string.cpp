#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+5;
ll ans;
int a[N],n;
char c[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i]>>c[i];
	int l=1,r=n;
	while(l<=r){
		while(a[l]<=a[r]&&l<=r){
			if(c[l]!=c[r]){
				ans+=a[l];	
			}
			a[r]-=a[l];
			l++;
		}
		while(a[l]>a[r]&&r>=l){
			if(c[l]!=c[r]){
				ans+=a[r];
			}
			a[l]-=a[r];
			r--;	
		}
	}
	cout<<ans;
	return 0;
}

