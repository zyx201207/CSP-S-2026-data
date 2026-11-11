#include<bits/stdc++.h>
using namespace std;
int n,a[500005],z,x,s,k=1;
long long m;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	if(a[1]==a[n]){
		cout<<n;
		return 0;
	}
	for(int i=2;i<n;i++){
		if(a[i+1]-a[i]!=a[i]-a[i-1]){
			x=1;
			break;
		}
	}
	if(x==0){
		double o=m*2/(a[n]-a[n-1]);
		cout<<int(sqrt(o));
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int l=i+k;l<=n;l++){
			for(int j=i;j<l;j++)
				z+=a[l]-a[j];
			if(z<=m){
				if(l-i+1>s)
				s=l-i+1;
				k=l-i;
			}
			z=0;
		}
	}
	cout<<s;
	return 0;
} 
