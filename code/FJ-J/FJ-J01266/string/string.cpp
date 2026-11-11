#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	long long a[n+5];
	char b[n+5];
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}
	int l=1,r=n;
	long long s=0;
	while(l!=r){
		if(b[l]!=b[r]){
			s+=min(a[l],a[r]);
		}
		if(a[l]>=a[r]){
			a[l]-=a[r];
			a[r]=0;
			r--;
		}
		else{
			a[r]-=a[l];
			a[l]=0;
			l++;
		}
	}
	cout<<s;
	return 0;
}