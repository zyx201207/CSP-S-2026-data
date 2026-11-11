#include<bits/stdc++.h>
using namespace std;
const long long maxm=10000005;
long long x[maxm];
int R[maxm];
void solve(){
	int n;long long d;
	cin>>n>>d;
	for(int i=1;i<=n;i++){
		cin>>x[i];
	}
	int r=1;
	for(int i=1;i<=n;i++){
		if(r<i)r=i;
		while(r<n&&x[r+1]-x[i]<=d){
			r++;
		}
		R[i]=r;
	}
	long long ans=0;
	for(int u=1;u<=n;u++){
		int r1=R[u];
		if(r1-u<2)continue;
		int ye=R[r1-1];
		int ys=R[r1-2];
		long long count=(long long)ye-max(r1,ys);
		if(count>0)ans+=count;
	}
	cout<<ans<<endl;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int c,t;
	if(cin>>c>>t){
		while(t--){
			solve();
		}
	}
	return 0;
} 






























