#include<bits/stdc++.h>
using namespace std;
const int N=1e5*2+5;
int m,n;
int a[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(m==1){
		int mx=-0x3f3f3f3f;
		for(int i=1;i<=n;i++){
			mx=max(a[i],mx);
		}
		cout<<mx;
		return 0;
	}
	if(m==n){
		int ans=1;
		for(int i=1;i<n;i++){
			if(i==1) ans=(a[i]&a[i+1]);
			else ans=ans&a[i+1];
		}
		cout<<ans;
		return 0;
	}
	if(m==2){
		int mx=-0x3f3f3f3f;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				int z=(a[i]&a[j]);
				mx=max(mx,z);
			}
		}
		cout<<mx;
		return 0;
	}
	return 0;
}
