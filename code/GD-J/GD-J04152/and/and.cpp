#include<bits/stdc++.h>
using namespace std;
int o,n,a[200005],m,l,r,t,d[200005],d2[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;l=1,r=n;
	for(int i=1;i<=n;i++) cin>>a[i],d[++t]=a[i];
	sort(d+1,d+n+1);
	for(int i=29;i>=0;i--){
		int k=(1<<i),mi=r+1,ma=l-1,t2=0;
		for(int j=1;j<=t;j++) if(d[j]&k) d2[++t2]=d[j];
		if(t2>=m){
			o+=k,l=mi,r=ma;
			t=0;
			for(int j=1;j<=t2;j++) d[++t]=d2[j];
		}
	}
	cout<<o;
}
