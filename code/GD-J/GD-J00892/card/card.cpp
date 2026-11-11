#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=5e5+5;
int n,m,a[maxn],b[maxn],ans[maxn],r[maxn],l[maxn];
vector<int> id[maxn];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) b[i]=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
//		id[a[i]].push_back(i);
	}
	for(int i=1;i<=n;i++){
		int sta[maxn],top=0,lst[maxn];
		memset(lst,0,sizeof(lst));
		for(int j=i;j<=n;j++){
			if(lst[a[j]]) top=lst[a[j]];
			else sta[++top]=a[j],lst[a[j]]=top;
		}
		for(int j=1;j<=top;j++){
			ans[sta[j]]++;
		}
	}
//	for(int i=1;i<=m;i++){
//		for(int j=1;j<id[i].size();j++){
//			b[id[i][j-1]+1]-=id[i][j-1];
//			b[id[i][j]]+=id[i][j-1];
//		}
//	}
//	for(int i=2;i<=n;i++) b[i]+=b[i-1];
//	for(int i=1;i<=n;i++) ans[a[i]]=max(ans[a[i]],b[i]);
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
	return 0;
} 
