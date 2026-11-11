#include<bits/stdc++.h>
using namespace std;
#define N 1000010
#define int long long
int n,m,a[N],b[33];
vector<int>v;
int getp(int x,int pos){
	return (x>>(pos-1))&1;
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=32;i++){
		for(int j=1;j<=n;j++) b[i]+=getp(a[j],i);
	}
	for(int i=32;i;i--) if(b[i]>=m) v.push_back(i);
	for(int i=1;i<=n;i++){
		int tmp=0;
		for(int j=0;j<v.size();j++){
			if(getp(a[i],v[j])) tmp+=(1<<(v[j]-1));
		}
		a[i]=tmp;
	}
	sort(a+1,a+n+1);
	reverse(a+1,a+n+1);
	int ans=(1ll<<32)-1;
	for(int i=1;i<=m;i++) ans&=a[i];
	cout<<ans;
}
