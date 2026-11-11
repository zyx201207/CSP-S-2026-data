#include<bits/stdc++.h>
using namespace std;
long long x[200010];
char c[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	long long sum=0;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>x[i]>>c[i];
	}
	int l=0,r=n-1; 
	while(l<=r){
		if(c[l]!=c[r]) sum+=min(x[l],x[r]);
		if(x[l]<x[r]){
			x[r]-=x[l];
			l++;
		}
		if(x[l]>x[r]){
			x[l]-=x[r];
			r--;
		}
		else l++,r--;
	}
	cout<<sum;
	return 0;
} 

