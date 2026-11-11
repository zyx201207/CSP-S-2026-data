#include<bits/stdc++.h>
using namespace std;
int n,a[200005];
char c[200005];

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		cin>>c[i];
	}
	long long r=n,k=0,u=0;
	for(int l=1;l<=n;){
		if(abs(l-r)==1)u=1;
		if(l==r) break; 
		if(c[l]!=c[r]){
			if(a[l]>a[r]){
				a[l]-=a[r];
				k+=a[r];
				r--;			
			}else if(a[l]<a[r]){
				a[r]-=a[l];
				k+=a[l];
				l++;	
			}else{
				k+=a[l];
				r--;
				l++;
			}
		}
		else if(c[l]==c[r]){
			if(a[l]>a[r]){
				a[l]-=a[r];
				r--;
			}else if(a[l]<a[r]){
				a[r]-=a[l];
				l++;
			}else{
				r--;
				l++;
			}
		}
	
		if(u==1) break;
	}
	cout<<k;
	return 0;
} 

