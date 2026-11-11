#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+10;
#define ll long long
int n,m,ans; 
int t[35];
ll a[maxn];
bool vis[35];
vector<ll>f;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++) cin >> a[i];
	for(int i=1;i<=n;i++){
		int res=1,cnt=a[i];
		while(a[i]){
			if(a[i]&1) t[res]++;
			res++;
			a[i]>>=1;
		}
		a[i]=cnt;
	}
	int cnt=0;
	for(int i=30;i>=0;i--){
		if(t[i]>=m){
			cnt=i;
			break;
		}
	}
	for(int i=1;i<=n;i++){
		int res=a[i]>>(cnt-1);
		if(res==1) f.push_back(a[i]);
		}		
	while(f.size()>=m){
		vis[cnt]=1;
		cnt--;
		for(auto i:f){
			if(i&(1<<cnt)==0) f.pop_back();
			if(f.size()<m) break;	
		}
	}
	for(int i=30;i>=0;i--)
		if(vis[i])
			ans+=(1<<i);
	cout << ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

