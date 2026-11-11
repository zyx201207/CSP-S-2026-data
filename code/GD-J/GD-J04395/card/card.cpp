#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],c[300005],r[300005],s,ans[300005],cnt;
bool p[300005];
set<int>h[300005],q;
int main(){
	freopen("card.in","r",stdin); 
	freopen("card.out","w",stdout); 
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		c[a[i]]++;r[a[i]]=i;
	}
	for(int i=n;i>=1;i--){
		q.insert(a[i]);
		if(p[a[i]]==0){
			p[a[i]]=1;
			h[a[i]]=q;
			cnt++;
			if(cnt==m)break;
		}else{
			q=h[a[i]];
		}
	}
	for(int i=1;i<=m;i++){
		while(h[i].size()){
			ans[*h[i].begin()]+=c[i];
			h[i].erase(*h[i].begin());
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
	return 0;
}
