#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+10,M=3e5+10;
ll n,m;
ll a[N],ans[M],mk[M];
queue<ll> q;
void sm(int step){
	int cnt=step;
	q.push(a[cnt]);
	mk[a[cnt]]=1;
	cnt++;
	while(cnt<=n){
		if(mk[a[cnt]]==1){
			int now=cnt-1;
			q.pop();
			while(a[now]!=a[cnt]){
				if(q.size()) q.pop();
				mk[a[now]]=0;
				now--;
			}
			q.push(a[cnt]);
			mk[a[cnt]]=1;
		}else{
			mk[a[cnt]]=1;
			q.push(a[cnt]);
		}
		cnt++;
	}
	for(int i=1;i<=m;i++){
		ans[i]+=mk[i];
	}
	memset(mk,0,sizeof(mk));
	while(q.size()){
		q.pop();
	}
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		sm(i);
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
/*
4 3
1 2 1 3

*/
