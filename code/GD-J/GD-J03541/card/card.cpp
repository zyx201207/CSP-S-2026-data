#include<bits/stdc++.h>
using namespace std;

long long n,m,last[300005],vis[500005],a[500005],ans[300005],tree[500005];

long long lowbit(int x){
	return x & -x;
}

void add(int x,int y){
	for(int i=x;i<=n;i+=lowbit(i)){
		tree[i]+=y;
	}
}

long long query(int x){
	long long tot=0;
	for(int i=x;i;i-=lowbit(i)){
		tot += tree[i];
	}
	return tot;
}

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			vis[j]=0;
			last[a[j]]=0;
			tree[j]=0;
		}
		for(int j=i;j<=n;++j){
			long long id=last[a[j]];
			if(id != 0 and query(id) == 0){
				add(id,1);
				add(j,-1);
			}
			last[a[j]] = j;
		}
		for(int j=i;j<=n;++j){
			if(query(j) == 0){
				ans[a[j]]++;
			}
		}
	}
	for(int i=1;i<=m;++i){
		cout<<ans[i]<<" ";
	}
	return 0;
} 
