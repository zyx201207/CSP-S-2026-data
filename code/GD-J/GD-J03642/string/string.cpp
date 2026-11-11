#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,a[N];
long long ans;
char c[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i]>>c[i];
	}int l=0,r=n-1;
	while(l<=r){
		if(c[l]!=c[r]){
			if(a[l]==a[r]){
				ans+=a[r];
				l++,r--;
			}else if(a[l]>a[r]){
				ans+=a[r];
				a[l]-=a[r];
				r--;
			}else{
				ans+=a[l];
				a[r]-=a[l];
				l++;
			}
		}else{
			if(a[l]==a[r]){
				l++,r--;
			}else if(a[l]>a[r]){
				a[l]-=a[r];
				r--;
			}else{
				a[r]-=a[l];
				l++;
			}
		}
	}cout<<ans;
} 
