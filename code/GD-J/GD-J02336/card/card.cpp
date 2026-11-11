#include<bits/stdc++.h>
using namespace std;

int a[500005];
int ans[300005];
bool b[300005];

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n,m; cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		memset(b,false,sizeof(b));
		vector<int>v;
		for(int j=i;j<=n;j++){
			if(b[a[j]]){
				while(v.back()!=a[j]){
					b[v.back()]=false;
					v.pop_back();
					//cout<<v.back()<<'\n';
				}
				v.pop_back();
			}
			v.push_back(a[j]);
			b[a[j]]=true;
		}
		for(int j=1;j<=m;j++){
			if(b[j])ans[j]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
	
	return 0;
}//4 3 1 2 1 3
