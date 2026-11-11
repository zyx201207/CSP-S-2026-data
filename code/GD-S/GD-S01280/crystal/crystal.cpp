#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
typedef long long ll;
int n;
ll m,a[N];
void commonSolve(){
	ll ans,k,ma=1;
	for(int i=1;i<=n;i++){
		ans=1,k=0;
		int u=i;
		while(++u<=n&&a[i]==a[u]) ans++;
		for(int j=i-1;j>0;j--){
			k+=a[i]-a[j];
			if(k<=m) ans++;
		}
		ma=max(ma,ans);
	}
	cout<<ma;
}
void specialSolve(){
	ll ans=1,ca=a[2]-a[1],sum=0;
	for(int i=n-1;i>0;i--){
		sum+=ca;
		if(sum<=m) ans++,m-=sum;
		 else break;
	}
	cout<<ans;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>a[1];
	bool flag=0;
	for(int i=2;i<=n;i++){
		cin>>a[i];
		if(abs(a[i]-a[i-1])!=abs(a[2]-a[1])) flag=1;
	}
	sort(a+1,a+1+n);
	if(flag) commonSolve();
	 else specialSolve();
	return 0;
}

