#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+7,M=15e7;
int n,m,mx,tot;
int a[N],s[N],ans[M];
bool f=1,f2=1;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	tot=n;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		if(a[i]!=i){
			f=0;
			break;
		}
	}
	if(f==1){
		for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
		for(int i=n-1;i>=1;i--){
			if(m>=s[i]){
				cout<<i+1<<"\n";
				return 0;
			}
		}
	}
	sort(a+1,a+n+1);
	int b=a[2]-a[1];
	for(int i=2;i<=n;i++){
		if(a[i+1]-a[i]!=b){
			f2=0;
			break;
		}
	}
	if(f2==1){
		for(int i=1;i<=n;i++) s[i]=s[i-1]+i;
		for(int i=n;i>=1;i--){
			if(m>=s[i]*b){
				cout<<i+1<<"\n";
				return 0;
			}
		}
	}
	for(int i=1;i<=n;i++) s[i]=a[i]-a[i-1];
	for(int l=n;l>=1;l--){
		for(int i=1,j;i<=n;i++){
			j=i+l-1,b=0;
			if(j>n) break;
			for(int k=1;k<l;k++) b+=s[k+i-1]*k;
			if(b<=m){
				cout<<l<<"\n";
				return 0;
			}
		}
	}
	return 0;
}
