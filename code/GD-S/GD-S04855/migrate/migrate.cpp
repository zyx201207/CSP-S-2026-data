#include <bits/stdc++.h>
using namespace std;
int c,r,n,m,t,ans=0;
vector<int> a;
//µ∫”Ïæ‡¿Î 
map<int,int> vis,mp;
//vis->ƒ‹∑ÒµΩ¥Ô 
long long fi(long long x){ //x->µ∫”Ï±‡∫≈ 
	long long f=a[x],k=m;
	while(!vis[f-k]&&k>0) k--;
	return k; //∑µªÿæ‡¿Î 
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >>c >> t;
	while(t--){
		cin >> n >> m;
		a.push_back(0);
		for(int i =1;i<=n;i++){
			int x;cin >> x;
			a.push_back(x);
			vis[x]=i;
		}
		for(int i=1;i<=n-3;i++){
			mp[i]=0;
			for(int j =i+1;j<=n;j++){
				int f=a[j];
				if(f-m<a[i]&&abs(vis[f-m])){
					mp[j]=1;
					continue;
				}
				else{
					int k=fi(j);
					
					if(!k) break;
					mp[j]=mp[vis[f-k]]+1;
				}
			}
			for(long long j=i+3;j<=n;j++){
				if(mp[j-1]==mp[j-2]&&mp[j-3]!=mp[j-2]&&mp[j]!=mp[j-1]) ans++;
			}
		}
		cout << ans << endl;
	}
	return 0;
}
