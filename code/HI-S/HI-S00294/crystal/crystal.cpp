#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500009],b[500009],ans=-1e12-10;

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	cin>>a[0];
	b[0]=0;
	for(int i=1;i<n;i++) cin>>a[i];
	sort(a,a+n);
	for(int i=1;i<n;i++) b[i]=a[i]-a[i-1]+b[i-1];
	for(long long i=1;i<n;i++){
		for(long long  j=0;j<i;j++){
			if(m>=b[i]-b[j]){
				ans=max(ans,(i-j)+1);
			}
		}
	}
	cout<<ans;
	return 0;
}
