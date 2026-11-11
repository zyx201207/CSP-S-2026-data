#include<bits/stdc++.h>
using namespace std;
const int N=5e5+50;
long long n,m,a[N],c[N],qz[N],ma=-1,qqz[N],kbl,fk;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	bool f=1;
	for(int i=2;i<=n;i++){
		if(i==2) kbl=a[i]-a[i-1];
		else{
			if(a[i]-a[i-1]!=kbl) f=0;
		}
	}
	if(f){
		long long yi=n;
		for(int i=1;i<=n;i++){
			fk=(i*(i-1)*kbl/2);
			if(fk>m){
				yi=i-1;
				break;
			}
		}
		cout<<yi;
		return 0;
	}
	for(int i=1;i<n;i++){c[i]=a[i+1]-a[i];}
	for(int i=n-1;i>=1;i--) qz[i]=qz[i+1]+c[i];
	for(int i=1;i<n;i++) qqz[i]=qqz[i-1]+qz[i];
	//
//	for(int i=1;i<n;i++) cout<<c[i]<<" ";
//	cout<<'\n';
//	for(int i=1;i<n;i++) cout<<qz[i]<<" ";
//	cout<<'\n';
//	for(int i=1;i<n;i++) cout<<qqz[i]<<" ";
//	cout<<'\n';
	// 
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(i==j) ma=max(ma,1ll);
			else{
	//			cout<<i<<" "<<j<<" "<<qqz[j-1]-qqz[i-1]-(j-i)*qz[j]<<'\n';
				if(qqz[j-1]-qqz[i-1]-(j-i)*qz[j]<=m) ma=max(ma,j-i+1ll);
				else break;
			}
		}
	}
	cout<<ma;
	return 0;
} 
