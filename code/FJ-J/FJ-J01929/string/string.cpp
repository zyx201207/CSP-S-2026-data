#include<bits/stdc++.h>
using namespace std;
int n,a[200005],l,r;
long long sum;
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i]>>c[i];
	}
	r=n-1;
	while(1){
		if(c[l]!=c[r]){
			if(a[l]==a[r]){
				sum+=a[l];
				l++;
				r--;
			}
			else if(a[l]<a[r]){
				sum+=a[l];
				a[r]-=a[l];
				l++;
			}
			else{
				sum+=a[r];
				a[l]-=a[r];
				r--;
			}
		}
		else{
			if(a[l]==a[r]){
				l++;
				r--;
			}
			else if(a[l]<a[r]){
				a[r]-=a[l];
				l++;
			}
			else{
				a[l]-=a[r];
				r--;
			}
		}
		if(l>=r){
			break;
		}
	}
	cout<<sum;
	return 0;
}
