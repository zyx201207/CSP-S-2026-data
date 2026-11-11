#include<bits/stdc++.h>
using namespace std;
int x[200010][33];
void fz(long long a,int k){
	int s=0,b=a;
	int y[33]={0};
	while(b){
		x[k][s++]=b%2;
		b/=2;
	}
	return;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[200010]={0};
	for(int i=0;i<n;i++){
		cin>>a[i];
		fz(a[i],i);
	}
	int js[33]={0};
	for(int i=0;i<32;i++){
		for(int j=0;j<n;j++){
			js[i]+=x[j][i];
		}
	}
	int r=0;
	int i=31;
	for(;i>=0;i--){
		if(js[i]>=m) break;
	}
	r=i;
	long long mod=pow(2,r+1),ans=pow(2,32)-1;
	int l=0;
	for(int i=0;i<n;i++){
		if(x[i][r]){
			a[i]%=mod;
			if(l<=m){
				ans=ans&a[i];
				l++;
			}
			else ans=max(ans,ans&a[i]);
		}
	}
	cout<<ans;
	return 0;
}
