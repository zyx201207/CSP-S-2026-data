#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	long long a[n+5];
	char c[n+5];
	for(int i=1;i<=n;++i){
		cin>>a[i]>>c[i];
	}
	int l=1,r=n;
	long long x=0;
	while(l<r){
		if(a[l]>a[r]){
			if(c[l]==c[r]){
				a[l]-=a[r];
				r--;
			}
			else if(c[l]!=c[r]){
				x+=a[r];
				a[l]-=a[r];
				r--;
			}
		}
		else if(a[l]==a[r]){
			if(c[l]==c[r]){
				l++;
				r--;
			}
			else if(c[l]!=c[r]){
				x+=a[l];
				l++;
				r--;
			}
		}
		else if(a[l]<a[r]){
			if(c[l]==c[r]){
				a[r]-=a[l];
				l++;
			}
			else if(c[l]!=c[r]){
				x+=a[l];
				a[r]-=a[l];
				l++;
			}
		}
	}
	cout<<x;
	return 0;
}
