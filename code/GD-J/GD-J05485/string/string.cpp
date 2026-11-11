#include<bits/stdc++.h>
#define int long long
using namespace std;
int n;
int a[200005];
char c[200005];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	int lg=0;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		lg+=a[i];
	}
	lg/=2;
	int l=1,r=n;
	int t=0;
	while(l<r){
		int s1=a[l];
		int s2=a[r];
		if(c[l]!=c[r]){
			t+=min(s1,s2);
			if(s1>s2){
				a[l]-=a[r];
				r--;
			}
			else if(s1<s2){
				a[r]-=a[l];
				l++;
			}
			else{
				l++;
				r--;
			}
		}
		else{
			if(s1>s2){
				a[l]-=a[r];
				r--;
			}
			else {
				a[r]-=a[l];
				l++;
			}
		}
	}
	cout<<t;
	return 0;
}
