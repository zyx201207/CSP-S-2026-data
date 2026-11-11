#include <bits/stdc++.h>
using namespace std;
long long a[200005];
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	long long l=1,r=n;
	long long ans=0;
	while(l<r){
		if(c[l]!=c[r]){
			if(a[l]>a[r]){
				ans+=a[r];
				a[l]-=a[r];
				r--;
			}else if(a[l]<=a[r]){
				ans+=a[l];
				a[r]-=a[l];
				l++;
			}
		}else if(c[l]==c[r]){
			if(a[l]>a[r]){
			
				a[l]-=a[r];
				r--;
			}else if(a[l]<=a[r]){
				
				a[r]-=a[l];
				l++;
			}
			
		}
	}
	cout<<ans;
	return 0;
}
