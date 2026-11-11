#include<bits/stdc++.h>
using namespace std;
const int maxn=200005;
int a[maxn];
char c[maxn];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i]>>c[i];
	}
	int l=0,r=n-1;
	long long ans=0;
	while(l<=r){
		if(a[l]>a[r]){
			if(c[l]!=c[r]){
				ans+=a[r];
			}
			a[l]-=a[r];
			r--;
		}
		else if(a[l]<a[r]){
			if(c[l]!=c[r]){
				ans+=a[l];
			}
			a[r]-=a[l];
			l++;
		}
		else{
			if(c[l]!=c[r]){
				ans+=a[l];
			}
			l++;
			r--;
		}
	}
	cout<<ans;
	return 0;
}
