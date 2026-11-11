#include <iostream>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,a[200005];
	char c[200005];
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		cin>>c[i];
	}
	long long s=0,l=1,r=n;
	while(l<r){
		if(a[l]<a[r]){
			if(c[l]!=c[r])s+=a[l];
			a[r]-=a[l];
			l++;
		}
		else if(a[l]==a[r]){
			if(c[l]!=c[r])s+=a[r];
			l++;
			r--;
		}
		else{
			if(c[l]!=c[r])s+=a[r];
			a[l]-=a[r];
			r--;
		}
	}
	cout<<s;
	return 0;
}
