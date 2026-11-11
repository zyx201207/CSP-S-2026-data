#include<bits/stdc++.h>
using namespace std;
long long n,ans,a[1000000];
char c[1000000];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i]>>c[i];
	int l=1,r=n,b;
	while(l<r){
		if(n%2&&r-l<2)break;
		if(n%2==0&&l>n/2)break;
		if(c[l]!=c[r]){
			if(a[l]<a[r]){
				a[r]-=a[l];
				l++;
				ans+=a[l];
			}else if(a[l]>a[r]){
				a[l]-=a[r];
				r--;
				ans+=a[r];
			}else{
				l++;
				r--;
				ans+=a[r];
			}
		}
	}
	cout<<ans;
	return 0;
}
