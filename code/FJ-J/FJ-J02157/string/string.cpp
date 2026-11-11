#include<bits/stdc++.h>
using namespace std;
long long a[200005],ans=0;
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i]>>c[i];
	}
	int l=0,r=n-1;
	while(true){
		if(a[l]>a[r]){
			if(c[l]!=c[r]){ans+=a[r];}
			a[l]=a[l]-a[r];
			r--;
		}
		else if(a[l]<a[r]){
			if(c[l]!=c[r]){ans+=a[l];}
			a[r]=a[r]-a[l];
			l++;
		}
		else{
		    if(c[l]!=c[r]){ans+=a[r];}
			l++;r--;
		}
		if(l>=r){break;}
	}
	cout<<ans;
	return 0;
}
