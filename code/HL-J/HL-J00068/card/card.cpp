#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[500010];
long long ans[500010];
int res[500010],s[500010],k;
vector<int> b[500010];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	bool f=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i>1&&a[i]<a[i-1]) f=1; 
	}
	if(!f){
		for(int i=1;i<=n;i++){
			if(i==n||a[i]!=a[i+1]){
				ans[a[i]]+=i;
			}
		}
		for(int i=1;i<=m;i++){
			cout<<ans[i]<<" ";
		}
		return 0;
	}
	for(int T=1;T<=n;T++){
		for(int i=1;i<=m;i++) b[i].clear();
		k=0;
		for(int i=T;i<=n;i++){
			if(!b[a[i]].empty()){
				for(int j=b[a[i]].back()+1;j<=k;j++){
					b[s[j]].pop_back();
				}
				k=b[a[i]].back();
			}
			else{
				s[++k]=a[i];
				b[a[i]].push_back(k);
			}
		}
		for(int i=1;i<=k;i++) ans[s[i]]++;
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}

/*
4 3
1 2 1 3

 10 3
3 1 2 1 3 2 3 1 2 1


*/