#include<bits/stdc++.h>
using namespace std;

constexpr int N=5e5+9,M=3e5+9;

//dex[k]：点数为 k 的牌在 q 中的下标 
int n,m,a[N],cnt[M],dex[M];

vector<int> q;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	q.reserve(500010);
	for(int i=0;i<M;i++) dex[i]=-1;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			int k=a[j];
			if(dex[k]==-1){
				q.push_back(k);
				dex[k]=q.size()-1; 
			}
			else{
				int tmp=dex[k];
				for(int l=1;l<=q.size()-tmp;l++){
					dex[q.back()]=-1;
					q.pop_back();
				}
			}
		}
		for(auto x:q) cnt[x]++;
	}
	for(int i=1;i<=m;i++) cout<<cnt[i]<<' ';
	return 0;
}

