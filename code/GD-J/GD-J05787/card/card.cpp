#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	vector<int> a(n+1);
	vector<int> ans(n+1,0);
	
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		vector<int> b;
		vector<int> vis(n+1,0);
		for(int j=i;j<=n;j++){
			if(!vis[a[j]]){
				b.push_back(a[j]);
				vis[a[j]]=1;
			}
			else{
				int x;
				for(int q=0;q<b.size();q++){
					if(b[q]==a[j]) 
					{
						x=q;
						break;
					}
					
				}
				int y=b.size();
				for(int l=x+1;l<y;l++){
					vis[b[l]]=0;
					b.erase(b.begin()+l);
				}
				
			}
		} 
		for(int j=0;j<b.size();j++) ans[b[j]]++;
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
	
	return 0;
}
