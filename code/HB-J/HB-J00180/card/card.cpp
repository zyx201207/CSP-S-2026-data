#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	int cnt[500005];
	cin>>n>>m;
	int cd[500005]={0};
	for(int i=1;i<=n;i++){
		cin>>cd[i];
	}
	for(int i=1;i<=n;i++){
		vector<int> fst(n+1);
		for(int j=1;j<=n;j++) fst[j]=-1;
		int l=1,r=1;
		for(int j=i;j<=n;j++){
			if(fst[cd[j]]==-1) fst[cd[j]]=j;
			if(j!=fst[cd[j]]) {
				l=j;
				r=j;
				fst[cd[j]]=j;
				for(int p=1;p<=m;p++){
					if(p==cd[j]) p++;
					fst[p]=-1;
				}
			}
			//cout<<j<<"th:";
			//for(int j1=1;j1<=m;j1++) cout<<fst[j1]<<" \n"[j1==m];
			r++;
		}
		for(int j=1;j<=m;j++){
			if(fst[j]!=-1) cnt[j]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<cnt[i]<<' ';
	}
	return 0;
}
