#include <bits/stdc++.h>
#define pb push_back
using namespace std;

vector<int> a;
vector<int> b;

int check(int k){
	for (int i=0;i<b.size();i++){
		if (b[i]==k) return i;
	} return -1;
}

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	
	int n,m;
	cin>>n>>m;
	a.pb(0);
	for (int i=1;i<=n;i++){
		int k;cin>>k;
		a.pb(k);
	}
	
	int ans[m+1];
	memset(ans,0,sizeof(ans));
	
	for (int i=1;i<=n;i++){
		for (int j=i;j<=n;j++){
			int s=check(a[j]);
			if (s==-1){
				b.pb(a[j]);
			}
			else{
				b.erase(b.begin()+s,b.begin()+b.size());
				b.pb(a[j]);
			}
		}
		
		int cnt[m+1];
		memset(cnt,0,sizeof(cnt));
		for (int j=0;j<b.size();j++){
			cnt[b[j]]++;
		}
		
		for (int j=1;j<=m;j++){
			if (cnt[j]!=0) ans[j]++;
		}
		
		b.erase(b.begin(),b.begin()+b.size());
	}
	
	for (int i=1;i<=m;i++) cout<<ans[i]<<" ";
	return 0;
}
