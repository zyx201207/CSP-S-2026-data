#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long k=0;
	int n;
	cin>>n;
	char x[n+1];
	int p[n+1];
	for(int i=0;i<n;i++){
		cin>>p[i]>>x[i];
	}
	int l=0,r=n-1;
	while(l<=r){
		if(x[l]!=x[r]){
			if(p[l]>p[r]) k+=p[r];
			else if(p[l]<p[r]) k+=p[l];
			else k+=p[r];
		}
		if(p[l]>p[r]){
			p[l]=p[l]-p[r];
			r--;
		}
		else if(p[l]<p[r]){
			p[r]=p[r]-p[l];
			l++;
		}
		else{
			r--;
			l++;
		}
	}
	cout<<k;
	return 0;
}
