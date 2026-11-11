#include<bits/stdc++.h>
using namespace std;
int n,a[200333],j,l,r;
long long js=0;
char c[200333];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	j=n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		cin>>c[i];
	} 
	l=1;
	r=n;
	while(j>=1){
		if(a[l]>=a[r]){
			if(a[l]>a[r]){
				a[l]=a[l]-a[r];
			if(c[l]!=c[r]){ 
				js=js+a[r];
			}
			r--;
			j--;
			}
		    else{
		    	if(c[l]!=c[r]){ 
				js=js+a[r];
			}
			    j=j-2;
			    l++;
			    r--;
			}
		}
		else if(a[l]<a[r]){
				a[r]=a[r]-a[l];
			if(c[l]!=c[r]){ 
				js=js+a[l];
			}
			l++;
			j--;
		}
	}
	cout<<js;
	return 0;
} 
