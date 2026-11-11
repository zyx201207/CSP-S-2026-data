#include<bits/stdc++.h>
using namespace std;
int t,a[200005];
int ans;
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>a[i]>>c[i];
	}
	int i=1,j=t,l=0,r=a[t]+1;
	while(i<=j){
		l++;
		r--;
		if(l>a[i]){
			i++;
			l=1;
		}
		if(r<1){
			j--;
			r=a[j];
		}
		if(i==j&&l>=r){
			break;
		}
		if(i<=j&&c[i]!=c[j]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
