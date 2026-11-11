#include <bits/stdc++.h>
using namespace std;
int a[200001];
char c[200001];
long long sum[200001],ans,num;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		sum[i]=sum[i-1]+a[i];
		num+=a[i];
	}
	if(num%2==1){
		for(int i=1;i<=n;i++){
			if(sum[i]>(num/2)){
				a[i]--;
				break;
			}
		}
	}
	int l=1,r=n;
	while(l<r){
		while(a[l]>=a[r]){
			if(c[l]!=c[r]){
				ans+=a[r];
			}
			a[l]-=a[r];
			r--;
		}
		if(!(l<r)){
			break;
		}
		while(a[r]>=a[l]){
			if(c[l]!=c[r]){
				ans+=a[l];
			}
			a[r]-=a[l];
			l++;
		}
	}
	cout<<ans;
	return 0;
}
