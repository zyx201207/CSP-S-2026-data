#include<bits/stdc++.h>
using namespace std;
long long n,a[200010];
char c[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		cin>>c[i];
	} 
	int l=1,r=n,t=0;
	while(l<=r){
		if(c[l]==c[r]){
			if(a[l]==a[r]){
				l++;
				r--;
			}
			else if(a[l]<a[r]){
				a[r]-=a[l];
				l++;
			}
			else if(a[l]>a[r]){
				a[l]-=a[r];
				r--;
			}
		}
		else if(c[l]!=c[r]){
			if(a[l]==a[r]){
				t+=a[l];
				l++;
				r--;
			}
			else if(a[l]<a[r]){
				t+=a[l];
				a[r]-=a[l];
				l++;
			}
			else if(a[l]>a[r]){
				t+=a[r];
				a[l]-=a[r];
				r--;
			}
		}
	}
	cout<<t;
	return 0;
}
