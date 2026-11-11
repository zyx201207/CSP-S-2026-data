#include<bits/stdc++.h>
using namespace std;
int n,a[200020],s;
long long ans;
char z[200020];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>z[i];
	}
	int l=1,r=n;
	while(l<r){
		if(z[l]!=z[r]){
			if(a[l]>a[r]){
				a[l]-=a[r];
				ans+=a[r];
				r--;
			}
			else if(a[r]>a[l]){
				a[r]-=a[l];
				ans+=a[l];
				l++;
			}
			else{
				ans+=a[l];
				l++;
				r--;
			}
		}
		else if(a[l]>a[r]){
			a[l]-=a[r];
			r--;
		}
		else if(a[l]<a[r]){
			a[r]-=a[l];
			l++;
		}
		else{
			r--;
			l++;
		}
	}
	cout<<ans;
	return 0;
}
