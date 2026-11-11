#include<bits/stdc++.h>
using namespace std;
long long n,m;
const int MAXN=5e5+5;
long long a[MAXN];
long long cnt=1e12;
int ans=0;
bool flag2=true;
bool flag1=false;
int j=-1;
long long ef(long long r,long long l){
	long long mid=(r+l)/2;
	int s=0;
	long long h=0;
	long long g=-1e18;
	for(int i=1;i<=n;i++){
		if(mid>=a[i]){
			h+=mid-a[i];
			s++;
		}
		
	}
	if(r==l||abs(r-l)==1){
		if(j==1) flag1=true;
		j++;
	} 
	
	if(h<=m&&flag2){
		ans=max(ans,s);
		r=mid+1;
		if(flag1) flag2=false;
		ef(r,l);
	}
	else if(h>m&&flag2){
		l=mid-1;
		if(flag1) flag2=false;
		ef(r,l);
	}
	else return ans;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	long long zx,zd;
	zx=1e12;
	zd=-1e12;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		zx=min(zx,a[i]);
		zd=max(zd,a[i]);
	}
	ef(zx,zd);
	cout<<ans;
	return 0;
}
