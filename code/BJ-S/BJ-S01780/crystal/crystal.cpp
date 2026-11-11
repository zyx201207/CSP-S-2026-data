#include<bits/stdc++.h>
using namespace std;
long long n,a[500005],m,s[500005],sm[500005],f[500005],ans[500005],mans=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		s[i]=a[i]-a[1];
	}
	sm[1]=s[1];
	for(int i=1;i<=n;i++){
		sm[i]=sm[i-1]+s[i];
	}
	for(int i=1;i<=n;i++){
		f[i]=s[i]*i-sm[i];
	}
	int l,r,mid;
	for(int i=1;i<=n;i++){
		l=i;
		r=n;
		mid=(l+r)/2;
		while(l<r){
			if(f[mid]-f[i]>m){
				r=mid;
				mid=(l+r)/2;
			}
			else if(f[mid]-f[i]<=m){
				if(f[mid+1]-f[i]>m){
					ans[i]=mid-i+1;
					break;
				}
				else{
					l=mid;
					mid=(l+r)/2;
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
		mans=max(mans,ans[i]);
	}
	cout << mans;
	return 0;
}
