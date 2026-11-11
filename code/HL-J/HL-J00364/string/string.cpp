#include<bits/stdc++.h>
using namespace std;
long long a[200010];
char c[200010];
int main(){
	long long n,ans=0;
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	int l=1,r=n;
	while(l<=r){
		if(a[l]>a[r]){
			if(c[l]!=c[r]){
				ans+=a[r];
			}
			a[l]-=a[r];
			r--;
		}else if(a[r]>a[l]){
			if(c[l]!=c[r]){
				ans+=a[l];
			}
			a[r]-=a[l];
			l++;
		}else{
			if(c[l]!=c[r]){
				ans+=a[l];
			}
			l++;
			r--;
		}
	}
	cout<<ans;
	return 0;
}
