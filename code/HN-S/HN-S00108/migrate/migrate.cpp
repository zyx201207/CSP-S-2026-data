#include<bits/stdc++.h>
using namespace std;
int c,t,a[1000005];
int n,m,h,ans;
int zd(int x,int z,int bs){
	int dp,i=x,zx=100000005;
	while(m>=dp+a[i+1]){
		i++;
		dp+=a[i];
		if(i==z) return bs;
		zx=min(zx,zd(i,z,bs+1));
	}
	return zx;
}
int jg(int x,int z,int bs){
	int dp,i=x,zx=100000005,ans;
	while(m>=dp+a[i+1]){
		i++;
		dp+=a[i];
		if(i==x||bs==h){
			ans++;
			return ans;
		}
		zx=min(zx,jg(i,z,bs+1));
	}
	if(zx==h){
		ans++;
	}
	return zx;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	int l;
	while(t--){
		cin>>n>>m;
		for(int i=0,x,s=0,q;i<n;i++){
			cin>>x;
			if(i) a[i-1]=x-s;
			s=x;
		}
		for(int i=0;i<n-2;i++){
			for(int j=i+2;j<n-1;j++){
				h=zd(i,j,1);
				ans=0;
				jg(i,j,1);
				if(ans==2){
					l++;
				}
			}
			cout<<l<<endl;
		}
	}
	return 0;
}
