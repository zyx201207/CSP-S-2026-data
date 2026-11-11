#include<bits/stdc++.h>
using namespace std;
int a[200005],n;
char c[200005];
long long ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i]>>c[i];
	}
	for(int i=0,cj=1;i<a2n-cj;){
		if(c[i]!=c[n-cj]){
			ans+=min(a[i],a[n-cj]);
		}
		if(a[i]>a[n-cj]){
			a[i]-=a[n-cj];
			cj++;
		}else if(a[i]==a[n-cj]){
			i++;
			cj++;
		}else{
			a[n-cj]-=a[i];
			i++;
		}
	}
	cout<<ans;
	return 0;
}
