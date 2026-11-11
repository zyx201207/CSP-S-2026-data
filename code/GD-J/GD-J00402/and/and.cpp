#include<bits/stdc++.h>
#define int long long
using namespace std;
long long a[200005];
vector<int> G[35];
bool cmp(int o,int p){
	return a[o]>a[p];
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	scanf("%lld %lld",&n,&m);
	for(int i=1; i<=n; i++){
		scanf("%lld",&a[i]);
		int t=a[i],cnt=0;
		while(t){
			if(t&1){
				G[cnt].push_back(i);
			}
			t>>=1;
			cnt++;
		}
	}
//	for(int i=0; i<=6; i++){
//		for(int j=0; j<G[i].size(); j++){
//			cout<<G[i][j]<<" ";
//		}
//		cout<<endl;
//	}
//	sort(a+1,a+n+1,greater<long long>());
	int id=-1;
	for(int i=31; i>=0; i--){
		if((int)G[i].size()>=m){
			id=i;
			break;
		}
	}
//	cout<<id<<endl;
	if(id==-1){
		printf("0");
		return 0;
	}
	sort(G[id].begin(),G[id].end(),cmp);
	int ans=a[G[id][0]];
//	printf("%lld ")
	for(int i=1; i<m; i++){
		ans&=a[G[id][i]];
//		printf("%lld ",a[G[id][i]]);
	}
	printf("%lld",ans);
	return 0;
}
