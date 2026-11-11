#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[500005],b[300005];
vector<int> s[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		s[a[i]].push_back(i);
	} 
	for(int i=1;i<=n;i++){
		int u=a[i],ui=i,v=s[u].size();
		while(ui<=n){
			b[u]++;
			ui=s[u][v-1]+1;
			u=a[ui];
			v=s[u].size();
		}
		
	}
	for(int i=1;i<=m;i++) cout<<b[i]<<" ";
	cout<<endl;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
