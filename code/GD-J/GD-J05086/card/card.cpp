#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=5e5+5,M=5e3+3;
int a[N],ans[N];
vector<int> zhuo;
int fin(int x){
	for(int i=0;i<zhuo.size();++i)if(zhuo[i]==x)return i;
	return 1e8; 
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;cin>>n>>m;
	for(int i=1;i<=n;++i)cin>>a[i];
	if(n<=3000){
		for(int i=1;i<=n;++i){
			for(int j=i;j<=n;++j){
				int id=fin(a[j]);
				if(id!=1e8){
					for(int i=id+1;i<zhuo.size();++i){
						zhuo[i]=-1;
					}
				}
				else zhuo.push_back(a[j]);
			}
			for(int v:zhuo){
				ans[v]++;	
			}
			zhuo.clear();
		}		
	}
	else {
		for(int i=1;i<=n;++i){
			ans[a[i]]++;
		}
		for(int i=1;i<=m;++i)ans[i]+=ans[i-1];
	}
	for(int i=1;i<=m;++i)cout<<ans[i]<<" ";
	return 0;
}

