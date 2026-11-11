#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,s=0;
	cin>>n;
	int a[n];
	char b[n]; 
	for(int i=0;i<n;i++){
		cin>>a[i]>>b[i];
	}
	long long l=0,r=n-1;
	long long ln=0,rn=0;
	while(l<=r){
		if(ln==0){
			ln+=a[l];
		}
		if(rn==0){
			rn+=a[r];
		}
		if(b[l]!=b[r]){
			s+=min(ln,rn);
		}
		if(ln>rn){
			ln=ln-rn;
			rn=0;
			r--;
		}
		else if(ln<rn){
			rn=rn-ln;
			ln=0;
			l++;
		}
		else{
			ln=0;
			rn=0;
			l++;
			r--;
		}
	}


	cout<<s;
	return 0;
}
