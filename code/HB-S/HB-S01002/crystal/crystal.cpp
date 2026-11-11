#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=5e5+5;
int n; ll a[MAXN],p,q,m,ans=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i]; 
	sort(a+1,a+n+1); ll k=a[2]-a[1];
	for(int i=1;i<=n/2+1;i++){
		 p=q+i*2*k;
		 if(p>m){
			 ans=(i-1)*2;
			 if(i*k<=m-q) ans++;
			 break;
		 }
		 q=p;
	}
	cout<<ans+1<<'\n';
	return 0;
}
