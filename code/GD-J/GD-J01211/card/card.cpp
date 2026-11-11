#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	vector<int> a(n+1);
	for(int i = 1;i<=n;i++){
		cin>>a[i];
	}
	vector<int> ans(m+1,0);
	for(int cg = 1;cg<=n;cg++){
		vector<int> pos(m+1,-1);
		vector<int> exist(m+1,0);
		vector<int> table(n+1);
		int tend = 0;
		for(int i = cg;i<=n;i++){
			if(!exist[a[i]]){
				exist[a[i]] = 1;
				tend++;
				table[tend] = a[i];
				pos[a[i]] = tend;
			}
			else{
				for(int j = pos[a[i]]+1;j<=tend;j++){
					exist[table[j]] = 0;
					pos[table[j]] = -1;
					table[j] = 0;
				}
				tend = pos[a[i]];
			}
		}
		for(int i = 1;i<=m;i++){
			if(exist[i]){
				//cout<<"debug:"<<i<<"++£¡£¡"; 
				ans[i]++;
			}
		}
	}
	for(int i = 1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
