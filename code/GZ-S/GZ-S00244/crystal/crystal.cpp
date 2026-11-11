//GZ-S00244 遵义市第四中学 罗永淇 
#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
long long n,m,a[N],s[N],ans; 
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
	}
	for(int i=n;i>=2;i--){
		int l=1,r=i;
		while(l<=r){
			int mid=(l+r>>1);
			long long k=s[i-1]-s[mid-1];
			k=a[i]*(i-mid)-k;
			if(k<=m){
				r=mid-1;
			}
			else{
				l=mid+1;
			}
		}
		ans=max(ans,(long long)i-l+1);
	}
	cout<<ans;
	return 0;
}
