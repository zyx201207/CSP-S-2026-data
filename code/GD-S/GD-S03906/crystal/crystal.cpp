#include<bits/stdc++.h>
#define itn int
using namespace std;
const int N=5e5+10;
int n,m;
int a[N];
bool check(int x){
	int ned=0;
	for(int j=1;j<=x;j++){
		ned+=(a[x]-a[j]);
	}
	return ned<=m;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int l=1,r=n;
	if(n<=5000){
		for(int i=n;i>=1;i--){
			int ned=0;
			for(int j=i;j>=1;j--){
				if(ned>m)break;
				ned+=(a[i]-a[j]);
			}
			int ans=0;
			if(ned<=m){
				ans=max(ans,i);
			}
		}
	}else{
		while(l+1<r){
			int mid=(l+r)>>1;
//			cout<<mid<<endl;
			if(check(mid)){
				l=mid;
			}else{
				r=mid;
			}
		}
		cout<<l;
	}
	return 0;
}
