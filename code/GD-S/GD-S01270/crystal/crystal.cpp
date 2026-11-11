#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
const int maxn=5e5+5;
int n,m;
long long a[maxn],res;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);	
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	bool flagA=true;
	for(int i=1;i<=n;i++){
		if(a[i]!=i){
			flagA=false;
			break;
		}
	}
	if(flagA==true){
		for(int i=1;i<=n;i++){
			if((i-1)*i/2>m){
				cout<<i-1<<'\n';
				return 0;
			}
		}
		cout<<n<<'\n';
		return 0;
	}
	bool flagB=true;
	int d=a[2]-a[1];
	for(int i=1;i<n;i++){
		if(a[i+1]-a[i]!=d){
			flagB=false;
			break;
		}
	}
	if(flagB==true){
		for(int i=1;i<=n;i++){
			if((d+d+(i-2)*d)*(i-1)/2>m){
				cout<<i-1<<'\n';
				return 0;
			}
		}
		cout<<n<<'\n';
		return 0;
	}
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++){
		long long ans=1,tot=0,j=i-1;
		while(j>=1&&tot<=m){
			tot+=abs(a[i]-a[j]);
			if(tot<=m)ans++;
			j--; 
		}
		res=max(res,ans);
	}
	cout<<res<<'\n';
	return 0;
}
