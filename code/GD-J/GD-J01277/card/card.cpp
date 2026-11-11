#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500010];
long long ans[300010];
vector<long long> g[300010];
int main(){
	freopen("card.in","r","stdin");
    freopen("card.out","w","stdout");
	scanf("%lld%lld",&n,&m);
	for(long long i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		g[a[i]].push_back(i);
	}
	for(long long i=1;i<=n;i++){
		set<long long> st;
		st.insert(a[i]);
		long long j=g[a[i]].back();
		while(j<n){
			if(g[a[j]].back()!=j)j=g[a[j]].back();
			else j++,st.insert(a[j]);
		}
		for(long long v:st){
			ans[v]++;
		}
	}
	for(long long i=1;i<=m;i++){
		printf("%lld ",ans[i]);
	}
	return 0;
} 
