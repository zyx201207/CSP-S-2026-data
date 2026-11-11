#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int n,m;
vector<int> a;
vector<vector<int>> lg;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;++i){
		int t;
		scanf("%d",&t);
		a.push_back(t);
	}
	for(int i=0;i<n;++i){
		vector<int> dk;
		for(int j=i-1;j<n;++j){
			auto it=lower_bound(dk.begin(),dk.end(),a[j]);
			if(it!=dk.end()){
				while(dk.end()!=it)dk.pop_back();
			}
			dk.push_back(a[j]);
		}
		lg.push_back(dk);
	}
	for(int i=0;i<m;++i){
		int ans=0;
		for(auto &dk:lg)if(find(dk.begin(),dk.end(),i)!=dk.end())ans++;
		printf("%d ",ans);
	}
	return 0;
}
