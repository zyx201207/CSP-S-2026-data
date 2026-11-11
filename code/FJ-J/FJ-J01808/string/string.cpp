#include<bits/stdc++.h>
using namespace std;
long long n,a[200005],l=1,r,s=0;
char b[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	r=n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}
	while(l<r){
		if(b[l]!=b[r]){
			if(a[l]>a[r]){
				s+=a[r];
				a[l]-=a[r];
				r--;
			}
			else if(a[r]>a[l]){
				s+=a[l];
				a[r]-=a[l];
				l++;
			}
			else if(a[r]==a[l]){
				s+=a[l];
				l++;
				r--;
			}
		}
		else{
			if(a[l]>a[r]){
				a[l]-=a[r];
				r--;
			}
			else if(a[r]>a[l]){
				a[r]-=a[l];
				l++;
			}
			else if(a[r]==a[l]){
				l++;
				r--;
			}
		}
		
	}
	cout<<s;
	return 0;
} 
