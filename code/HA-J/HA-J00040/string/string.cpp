#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,a=0,x,g=0;
	cin>>n;
	int ab[n+5],gs[n+5];
	for(int i=0;i<n;i++){
		cin>>x;
		a+=x;
		gs[i]=x;
		cin>>ab[i];
	}
	x=a/2;
	n/=2;
	for(int i=0;i<x;i++){
		if(ab[i]!=ab[n-i-1]){
			if(gs[i]>=gs[n-i-1]){
				g+=gs[n-1-i];
				gs[i]-=gs[n-1-i];
				gs[n-1-i]=0;
				ab[n-1-i]=0;
				if(gs[i]=gs[n-i-1]) ab[i]=0;
			}
			else g+=gs[i];
			gs[n-1-i]-=gs[i];
			gs[i]=0;
			ab[i]=0;
		}
	}
	cout<<g;
	return 0;
}
