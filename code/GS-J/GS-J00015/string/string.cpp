#include<iostream>
using namespace std;
int n,l,r;
long long ans,a[200005];
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	l=1;r=n;
	while(l<=r){
		long long o=min(a[l],a[r]);
		if(a[l]<a[r]){
			a[r]-=a[l];
			a[l]=0;
		}else if(a[r]<a[l]){
			a[l]-=a[r];
			a[r]=0;
		}else{
			a[l]=a[r]=0;
		}
		if(c[l]!=c[r])ans+=o;
		if(a[l]<=0)l++;
		if(a[r]<=0)r--;
	}
	cout<<ans;
	return 0;
}
