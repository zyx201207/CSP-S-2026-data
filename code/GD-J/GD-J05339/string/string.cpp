#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	string c; 
	cin>>n;
	long long num=0,a[n],ans=0,f=0,b;
	for(int i=0;i<n;i++){
		cin>>a[i]>>c[i];
		num+=a[i];
	}
	int l=0,r=n-1;
	while(l<r){
		if(a[l]>a[r]){
			if(c[l]!=c[r]){
				ans+=a[r];
			}
			a[l]-=a[r]; 
			r--;
		}else {
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
