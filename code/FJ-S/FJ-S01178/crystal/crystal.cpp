#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+5,M=5005;
int n,sga;
ll m,a[N],b[N],c[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}sort(a+1,a+n+1);
	b[1]=a[1];
	bool flag=true;
	for(int i=2;i<=n;i++){
		b[i]=a[i]-a[i-1];
		if(b[i]!=b[i-1]&&i>3){
			flag=false;
		}
	}
	if(flag){
		for(int i=1;i<=n;i++){
			c[i]=c[i-1]+b[i]*(i-1);
			if(c[i]>m){
				cout<<i-1;
				return 0;
			}
		}
	}else{
		int r=1,sum=0;
		for(int l=1;l<=n;l++){
			while(sum<=m){
				r++;
				sum+=(a[r]-a[r-1])*(r-l);
			}
			sga=max(sga,r-l);
			sum-=a[r-1]-a[l];
		}cout<<sga;
	} 
	return 0;
}
