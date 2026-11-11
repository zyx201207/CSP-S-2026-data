#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5;
int n,m;
int a[N];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	bool r1=true;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=i) {
			r1=false;
		}
	}
	if(r1) {
		int i=1,tot=0;
		while(m>0) {
			m-=i;i++;
		}
		cout<<i;
		return 0;
	}
	int cnt=a[2]-a[1];
	bool r2=true;
	for(int i=2;i<=n;i++) {
		if(a[i]-a[i-1]!=cnt) {
			r2=false;
			break;
		}
	} 
	if(r2) {
		int i=1;
		while(m>0) {
			m-=cnt*i;
			i++;
		}
		if(m==0) cout<<i;
		else cout<<i-1;
		return 0;
	}
	int maxn=-0x3f3f3f3f,temp=m;
	for(int i=1;i<=n;i++) {
		int der=a[i],ans=0;
		for(int j=1;j<=n;j++) {
			if(a[j]<=der){
				temp-=(der-a[j]);
				if(temp<0){
					break;
				}
				ans++;
			}
		}
		maxn=max(maxn,ans);
		temp=m; 
	}
	cout<<maxn;
	return 0;
}
