#include<bits/stdc++.h>
using namespace std;

int main(){
	
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	
	int n;
	cin>>n;
	int a[n+5]={};
	char c[n+5]={};
	
	for(int i=1;i<=n;i++){
		cin>>a[i];
		cin>>c[i];
		
	}
	
	long long s=0;
	int l=1,r=n;
	while(l<r){
		if(c[l]==c[r]){
			if(a[l]>a[r]){
				a[l]-=a[r];
				r--;
				continue;
			}
			if(a[l]<a[r]){
				a[r]-=a[l];
				l++;
				continue;
			}
			if(a[l]==a[r]){
				l++;
				r--;
			}
		}
		else{
			if(a[l]>a[r]){
				s+=a[r];
				a[l]-=a[r];
				r--;
				continue;
			}
			if(a[l]<a[r]){
				s+=a[l];
				a[r]-=a[l];
				l++;
				continue;
			}
			if(a[l]==a[r]){
				s+=a[l];
				l++;
				r--;
			}
		}
		
	}
	cout<<s;
	
	return 0;
}
