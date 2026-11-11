#include <bits/stdc++.h>
using namespace std;
int main(){
	
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	int n,m;
	cin>>n>>m;
	
	vector<int>a(n+1);
	for(int i=1;i<=n;++i)cin>>a[i];
	
	vector<int>ans(m+1);
	auto play=[&](int pos)->void{
		vector<int>d(n+2);
		vector<int>last(m+1);
		vector<bool>f(m+1);
		for(int i=pos;i<=n;++i){
			if(!last[a[i]])last[a[i]]=i;
			else{
				++d[last[a[i]]],--d[i];
				for(int j=last[a[i]]+1;j<i;++j)last[a[j]]=0;
				last[a[i]]=i;
			}
		}
		for(int i=pos;i<=n;++i){
			d[i]+=d[i-1];
			if(!d[i]){
				if(!f[a[i]])++ans[a[i]];
				f[a[i]]=1;
			}
		}
	};
	for(int i=1;i<=n;++i)play(i);
	for(int i=1;i<=m;++i)cout<<ans[i]<<' ';
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
