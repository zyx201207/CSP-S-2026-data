#include <bits/stdc++.h>
using namespace std;
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int f=0;
	int n,m;cin>>n>>m;
	vector<int>a(n+1),ans(m+1);
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]<a[i-1]) f=0;
	}
	if(f){
		
	}else{
		for(int i=1;i<=n;i++){
			vector<int> t;
			for(int j=i;j<=n;j++){
				t.push_back(a[j]);
				for(int k=0;k<t.size();k++){
					if(t[k]==a[j]) t.erase(t.begin()+k,t.end()-1);
				}
			}
			for(auto it:t){
				if(it<=m) ans[it]++;
			}
		}
	}
	for(int i=1;i<m;i++) cout<<ans[i]<<' ';
	cout<<ans[m];
	return 0;
}
