#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	vector<int> a(n+5);
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	vector<int> ans(n+5,0);
	for(int i=1;i<=n;i++){
		vector<int> b;
		for(int j=i;j<=n;j++){
			for(int x=0;x<b.size();x++){
				if(b[x]==a[j]){
					for(int y=x;y<b.size();y++){
						b[y]=0;
					}
				}
			}
			b.push_back(a[j]);
		}
		for(int j=0;j<b.size();j++){
			ans[b[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
