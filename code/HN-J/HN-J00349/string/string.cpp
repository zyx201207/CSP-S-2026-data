#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+5;
int a[N],b[N],nl;
char c[N];
signed main(){
	ios::sync_with_stdio();cin.tie();cout.tie();
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		b[i]=b[i-1]+a[i];
		nl+=a[i];
	}
	nl=(nl+1)/2;
	int l=1,r=n,ans=0;
	
	while(l<r){
		if(b[l]>nl&&b[l-1]<nl||b[n]-b[r-1]>nl&&b[n]-b[r]<nl){
			if(b[l]>nl&&b[l-1]<nl){
				ans+=a[r];
				r--;
			}
			else{
				ans+=a[l];
				l++;
			}
		}
		else if(c[l]!=c[r]){
			if(a[l]==a[r]){
				ans+=a[l];
				l++;r--;
				continue;
			}
			if(a[l]<a[r]){
//				cout<<a[l]<<"\n";
				ans+=a[l];
				a[r]-=a[l];
				l++;
				continue;
			}
			if(a[l]>a[r]){
				ans+=a[r];
				a[l]-=a[r];
				r--;
				continue;
			}
		}
		else{
			if(a[l]==a[r]){
				l++;
				r--;
				continue;
			}
			if(a[l]<a[r]){
				a[r]-=a[l];
				l++;
				continue;
			}
			if(a[l]>a[r]){
				a[l]-=a[r];
				r--;
				continue;
			}
		}
	}
	cout<<ans<<'\n';
	return 0;
}
