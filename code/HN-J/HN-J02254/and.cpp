#include<bits/stdc++.h>
using namespace std;
int ejzy(int x){
	int k=1;
	while(k<x){
		k*=2;
	}
	return k-x;
}
int main(){
	freopen(and.in,"r",stdin);
	freopen(and.out,"w",stdout);
	int n,m;
	long long a;
	int s[200000],y[200000];
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a;
		s[i]=a;
	}
	sort(s,s+n);
	for(int i=0;i<n;i++){
		y[i]=ejzy(s[i]);
	}
	int gs=0;
	for(int i=n-1;i>=0;i--){
		if(y[i]==1){
			gs++;
			if(gs==m){
				cout<<s[i];
				break;
			}
		}
		if(s[i]==s[i-m+1] && i>=m-1){
			cout<<s[i];
			break;
		}
	}
	return 0;
}
