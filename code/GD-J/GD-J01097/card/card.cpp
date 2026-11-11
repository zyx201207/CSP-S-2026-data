#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5,M=3e5+5;
int n,m,ans[M],card[N],a[N];
bool f[M];
void solve(int k){
	memset(f,0,sizeof f);
	int cnt=0,pos[M];
	for(int i=k;i<=n;i++){
		if(f[card[i]]==0){
			a[++cnt]=card[i];
			f[card[i]]=1;
			pos[card[i]]=cnt;
		}else {
			for(int j=pos[card[i]]+1;j<=cnt;j++){
				f[a[j]]=0;
			}
			cnt=pos[card[i]];
		}
	}
	for(int i=1;i<=cnt;i++){
		ans[a[i]]++;
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>card[i];
	}
	for(int i=1;i<=n;i++){
		solve(i);
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
	return 0;
}
/*
10 3
3 1 2 1 3 2 3 1 2 1

3 1
1 
2 1
1 
3 1 
2 1
3 1
1
2 1
1
*/
