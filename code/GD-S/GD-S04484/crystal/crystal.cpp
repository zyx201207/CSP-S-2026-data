#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int n,m,ans;
int a[N],d[N],sum1[N],sum2[N];
int c(int r,int l){
	int res=0;
	for(int i=l;i<=r;i++){
		res+=a[r]-a[i];
	}
	return res;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	bool f=1,ff=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=i)f=0;
	}
	for(int i=2;i<n;i++){
		if(a[i]-a[i-1]!=a[i+1]-a[i])ff=0;
	}
	sort(a+1,a+n+1);
	a[0]=a[1];
//	cout<<endl;
	if(n<=5000){
		for(int i=1,l=1;i<=n;i++){
	//		ans=max(ans,i-l);
	//		cout<<c(i,l)<<" "<<i<<" "<<l<<endl;
			if(c(i,l)<=m){
				ans=max(ans,i-l+1);
			}
			else{
				while(l<i&&c(i,l)>m){
					l++;
				}
			}
		}
	}
	else if(f){
		int res=0;
		for(int i=1;i<=n;i++){
			if(res+i<=m){
				res+=i;
			}
			else {
				ans=i;
				break;
			}
		}
	}
	else if(ff){
		int res=0,d=a[2]-a[1];
		for(int i=1;i<=n;i++){
//			cout<<i*d<<endl;
			if(res+i*d<=m){
				res+=i*d;
			}
			else{
				ans=i;
				break;
			}
		}
	}
	cout<<ans;
}
