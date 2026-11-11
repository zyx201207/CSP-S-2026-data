#include<bits/stdc++.h>
using namespace std;
int n;
int ans=1;
int l,r;
int zx=0;

long long m;
long long a[10000006];
long long xynl;

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	cin>>n>>m;
	xynl=m;
	l=n-1;
	
	for(int i=1;i<=n;i++){
		cin>>a[i];	
	}
	
	sort(a+1,a+n+1);
	
	int dqdx=0-a[1]+1;
	
	if(a[1]<0){
		
		for(int i=1;i<=n;i++){
			a[i]+=dqdx;
		}
	}
	
	for(int i=n;i>=2;i--){
		ans=1;
		xynl=m;
		l=i-1;
		while(xynl>=(a[i]-a[l])&&l>0){
			xynl=xynl-(a[i]-a[l]);		
			ans++;
			l--;
		}
		zx=max(ans,zx);
	}
	cout<<zx;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
