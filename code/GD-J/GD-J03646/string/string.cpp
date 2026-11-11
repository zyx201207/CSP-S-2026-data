#include<bits/stdc++.h>
using namespace std;
int n,a[2000010];
char b[2000010];
long long ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		int x; char c;
		cin>>x>>c;
		a[i]=x; b[i]=c;
	}
	int l=1,r=n; 
	while(l<=r){
		if(b[l]!=b[r]){
			if(a[l]<a[r]){
				ans+=a[l];
				a[r]-=a[l];
				l++; 
			}else{
				ans+=a[r];
				a[l]-=a[r];
				r--;
			}
		}else{
			if(a[l]<a[r]){
				a[r]-=a[l];
				l++; 
			}else{
				a[l]-=a[r] ;
				r--;
			}
		}
	} 
	cout<<ans;
	return 0;
} 
