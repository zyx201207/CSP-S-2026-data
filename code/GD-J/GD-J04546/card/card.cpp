#include<bits/stdc++.h>
using namespace std;
int a[500005];
int aa[500005];
bool b[500005];
int n,m;
int t;
bool dd(int l,int r){
	if(r==n){
		for(int i=l;i<=r;i++){
			if(a[i]==t) return 1;
			return 0;
		}
	}
	for(int i=l;i<=r;i++){
		if(a[i]==a[r]&&!a[r]){
			for(int j=i+1;j<=r;j++){
				b[j]=1;
				r=j;
			}
		}
	}
	dd(l,r+1);
}
int main(){
	cin>>n>>m;
	int ans=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(t=1;t<n+1;t++){
		if(dd(1+t-1,1+t-1)) ans++;
	}
	cout<<ans;
	return 0;
}
