#include<bits/stdc++.h>
using namespace std;
const int N=1e5*5+5;
int n,m;
int a[N]={0},b[N]={0},c[N]={0};
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin.tie(0);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	for(int i=1;i<n;i++){
		b[i]=a[i]-a[i-1];
	}
	for(int i=1;i<n;i++){
		c[i]=b[i]*i+c[i-1];
	}
	for(int i=0;i<n;i++){
		if(c[i]>m){
			cout<<i;
			return 0;
		}
	}
	return 0;
} 
