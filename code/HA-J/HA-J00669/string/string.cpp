#include <bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n;
string s;
int a[N];
char c[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];	
	}
	int l=1,r=n;
	long long ans=0;
	while(l<=r){
		if(c[l]==c[r]){
			if(a[l]>a[r]){
				a[l]-=a[r];
				r--;
			}else if(a[r]>a[l]){
				a[r]-=a[l];
				l++;
			}else{
				l++;
				r--;
			}
		}else{
			if(a[l]>a[r]){
				ans+=a[r];
				a[l]-=a[r];
				r--;
			}else if(a[r]>a[l]){
				ans+=a[l];
				a[r]-=a[l];
				l++;
			}else{
				ans+=a[l];
				l++;
				r--;
			}
		}
	}
	cout<<ans;
	return 0;
}
