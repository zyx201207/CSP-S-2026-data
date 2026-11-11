#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+10; 
int n,k;
int a[N];
int f[N][35];
bool vis[N];
bool vec[N];
ll ans;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>k;
	vector<int> ve;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		int x=a[i];
		ve.clear();
		while(x){
			ve.push_back(x%2);
			x>>=1;
		}
		int sz=ve.size();
		for(int j=0;j<ve.size();j++){
			int t=ve[j];
			ve[j]=ve[sz-j-1];
			ve[sz-j-1]=t;
		}
		for(int j=0;j<sz;j++){
			f[i][j]=ve[j];
		}
		vis[i]=1;
//		for(int k=0;k<31;k++) cout<<f[i][k]<<' ';
//		cout<<'\n';
	}
	for(int mask=31;mask>=0;mask--){
		memset(vec,0,sizeof(vec));
		int cnt=0;
		for(int i=1;i<=n;i++){
			if(f[i][mask]==1 && vis[i]==1){
				cnt++;
				vec[i]=1;
			}
		}
//		for(int i=1;i<=n;i++) cout<<vis[i]<<' ';
//		cout<<'\n';
//		cout<<cnt<<'\n';
		if(cnt<k) continue;
		else{
			ans=ans+(1<<mask);
			for(int i=1;i<=n;i++){
				if(vec[i]==0) vis[i]=0;
			}
		}
	}
	cout<<ans<<'\n';
	return 0;
}
//Trick||Treat!
/*
4 2
3 15 12 12
*/
