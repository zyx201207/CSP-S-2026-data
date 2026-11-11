#include<bits/stdc++.h>
using namespace std;
long long n,a[200000],zs,l,r;
string c[200000];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i]>>c[i];		
	}
	r=n-1;
	while(l<r){
		if(a[l]>a[r]){
			if(c[l]!=c[r]){
			   zs+=a[r];
			}
			a[l]-=a[r];
			r--;	
		}else if(a[l]<a[r]){
		    if(c[l]!=c[r]){
			   zs+=a[l];
			}
			a[r]-=a[l];
			l++;
		}else if(a[l]==a[r]){
			if(c[l]!=c[r]){
			   zs+=a[r];
			}
			l++;
			r--;
		}
	}
	cout<<zs;
	return 0;
} 
