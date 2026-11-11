#include<bits/stdc++.h>
using namespace std;
int n,ans,t=1,tt=1;
long long m,a[500010],e;
int check(int e){
	long long s=0;
	int h=1;
	for(int i=1;i<e;i++) s+=a[e]-a[i],h++;
	if(s<=m) ans=max(ans,h);
	if(s<=m) return 1;
	else return 0;
}
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i==2) e=a[i]-a[i-1]; 
		if(a[i]-a[i-1]!=e&&i>2) tt=0;
		if(a[i]!=i) t=0;
	} 
	if(t==1){
		int w=0;
		for(int i=1;i<=n;i++){
			w+=i;
			if(w>m){
				cout<<i;
				return 0;
			} 
		}
	}
	if(tt==1){
		long long k=e;
		int f=1;
		while(k<m){
			k+=e;
			if(k<=m) f++;
		}
		cout<<f;
		return 0;
	}
	sort(a+1,a+1+n);
//	int l=1,r=n;
//	while(l<r){
//		int mid=(l+r+1)/2;
//		if(check(mid)) l=mid;
//		else r=mid-1;
//	}
//	cout<<ans<<' ';
	for(int j=1;j<=n;j++){
		int xk=0,nn=0;
		for(int k=j;k>0;k--){
			xk+=a[j]-a[k];
			if(xk<=m) nn++;
		}
		ans=max(ans,nn);
	}
	cout<<ans;
	return 0;
}
