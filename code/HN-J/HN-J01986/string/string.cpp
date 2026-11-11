#include<bits/stdc++.h>
using namespace std;
long long n,ans;
long long a[200020];
char c[200020];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
		cin>>c[i];
	}
	long long l=1,r=n;
	while(l<r){
		int minn=min(a[l],a[r]);
		if(c[l]!=c[r])
			ans+=minn;
		if(a[l]<a[r]){
			l++;
			a[r]-=minn;
		}
		else if(a[l]>a[r]){
			r--;
			a[l]-=minn;
		}
		else if(a[l]==a[r]){
			l++;
			r--;
		}
	}
	cout<<ans;
	return 0;
}
