//GZ-S0031,罗义凯，贵阳市第九中学 
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int MAXN=1e5+5;
int n,a[446198418],b[MAXN],c[5*MAXN],ma=1;
ll m;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	if(n==0){
		cout<<0<<'\n';
		return 0;
	}
	int p=1;
	for(int i=1;i<=n;i++){
		cin>>b[i];
	}
	sort(b+1,b+n+1);
	bool f=false;
	int e=1;
	for(int i=1;i<=n;i++){
		if(b[i]==b[i+1]){
			f=true;	
		}
		else{
			f=false;
		}
		if(f){
			e++;
			ma=max(ma,e);
		}
		for(int j=i;j<=n;j++){
			a[p+j-i]=b[j]-b[i];
		}
		p+=n-i+1;
		c[i]=p;
	}
	for(int i=1;i<=n;i++){
		int sum=0;
		for(int j=n-i+1;j>0;j--){
			sum+=a[c[j]-i];
		}
		if(sum<=m){
			cout<<max(n-i+1,ma)<<'\n';
			return 0;
		}
	}
	/*for(int i=1;i<=n-ma+1;i++){
		int sum=0,p=1;
		for(int j=n-i+1;j>0;j--){
			sum+=a[c[j]-i];
			mi[p]=min(mi[p],sum);
			p++;
		}
	}
	for(int i=n;i>=1;i--){
		if(mi[i]<=m){
			cout<<i<<'\n';
			return 0;
		}
	}*/
	return 0;
}
