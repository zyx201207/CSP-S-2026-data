#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int n,m,a[N],ans[N];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		unordered_map<int,int>b;
		for(int j=i;j<=n;j++){
			int id=b[a[j]];
			if(b[a[j]]!=0){
				for(auto c:b){
					if(c.second>=id)b[c.first]=0;
				}
			}
			b[a[j]]=j;
		}
		for(auto c:b){
			if(c.second!=0)ans[c.first]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}

