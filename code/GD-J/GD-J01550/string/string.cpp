#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+10;
int n;
char c[N];
ll a[N],ans=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	//debug
//	for(int i=1;i<=n;i++){
//		cout<<a[i]<<" "<<c[i]<<endl;
//	}
	int l=1,r=n;
	while(l<r){
		if(c[l]==c[r]){
			if(a[l]<a[r]){
				a[r]-=a[l];
				l++;
			}else if(a[l]>a[r]){
				a[l]-=a[r];
				r--;
			}else{
				l++;
				r--;
			}
		}else{
			if(a[l]<a[r]){
				ans+=a[l];
				a[r]-=a[l];
				l++;
			}else if(a[l]>a[r]){
				ans+=a[r];
				a[l]-=a[r];
				r--;
			}else{
				ans+=a[l];
				l++;
				r--;
			}
		}
//		cout<<l<<" "<<r<<" "<<ans<<'\n';
	}
	cout<<ans;
	return 0;
}
