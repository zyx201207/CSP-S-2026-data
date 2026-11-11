#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,iidx;
int a[N];
int idx[N];
int idx1[N];
char c[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	int mid=n/2;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	long long cnt1=0; 
	
	for(int i=1;i<=mid;i++){
		int ni=n-i+1;
		if(i==ni) break;
		if(i+1==ni){
			if(c[i]!=c[ni]){
				cnt1+=min(a[i],a[ni]);
			}
			break;
		}
		if(c[i]==c[ni]){
			if(a[i]<a[ni]){
				
				cnt1+=a[ni]-a[i]-idx[ni];
				a[ni-1]+=a[ni]-a[i];
				idx[ni-1]=a[ni]-a[i];
				
			}else if(a[i]>a[ni]){
				
				cnt1+=a[i]-a[ni]-idx[ni];
				a[ni-1]-=a[i]-a[ni];
			}
		}else{
			if(a[i]<a[ni]){
				
				cnt1+=a[i]-idx[ni];
				a[ni]-=a[i];
				idx[ni-1]=a[ni]-a[i];
				
			}else if(a[i]==a[ni]){
				
				cnt1+=a[i]-idx[ni];
				
			}else if(a[i]>a[ni]){
				
				cnt1+=a[i]-idx[ni];
				a[ni-1]-=a[i]-a[ni];
				
			}
		}
	}
	cout<<cnt1;
	return 0;
} 












