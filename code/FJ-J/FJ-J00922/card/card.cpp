#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n,m;
	
	cin >> n >> m;
	vector<int> c(n),t(m+1,0),ans(m+1,0);
	for(int i=0;i<n;i++) cin >> c[i];
	
	for(int u=0;u<n;u++){
		int cnt=1;
		
		for(int i=u;i<n;i++){
			if(t[c[i]]) for(int j=1;j<=m;j++) if(t[j]>t[c[i]]) cnt--,t[j]=0;
			else t[c[i]]=cnt;
			
			cnt++;
		}
		
		for(int i=1;i<=m;i++) if(t[i]) ans[i]++;
		
	}
	
	for(int i=1;i<=m;i++) cout << ans[i] << ' ';
	
	
	return 0;
}
