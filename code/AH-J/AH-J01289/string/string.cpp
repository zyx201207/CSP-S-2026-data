#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
long long a[N];
char c[N]; 
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	int l=1,r=n;
	unsigned long long ans=0;
	while(l<r){
		if(a[l]<a[r]){
			if(c[l]==c[r]){
				a[r]-=a[l];
				a[l]=0;
				l++;
			}
			else{
				ans+=a[l];
				a[r]-=a[l];
				a[l]=0;
				l++;
			}
		}
		else if(a[l]==a[r]){
			if(c[l]==c[r]){
				a[l++]=0;
				a[r--]=0;
			}
			else{
				ans+=a[l];
				l++;
				r--;
			}
		}
		else{
			if(c[l]==c[r]){
				a[l]-=a[r];
				a[r]=0;
				r--;
			}
			else{
				ans+=a[r];
				a[l]-=a[r];
				a[r]=0;
				r--;
			}
		}
	}
	cout<<ans;
	return 0;
}

