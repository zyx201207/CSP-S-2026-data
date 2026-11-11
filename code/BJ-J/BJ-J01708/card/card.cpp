#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
const int M=3e5+10;
#define ll long long


int n,m;
int a[N];
int nxt[M],nxti[N];
int ans[N];
bool pick[N];
bool s[5001];

void solve(int x){
	for(int i=1;i<=m;i++) s[i]=0;
	stack < pair <int,int> > q;
 	for(int i=1;i<=n;i++) pick[i]=0;
	for(int i=x;i<=n;i++){
		if(s[a[i]] == 0 ){
			pick[i]=1;
			s[a[i]]=1;
			q.push({a[i],i});
		}else{
			while( !q.empty() && q.top().first!=a[i] ){
				pick[ q.top().second ]=0,s[q.top().first]=0;
				q.pop();
			}
		}
	}
	for(int i=1;i<=n;i++){
		if(pick[i]) ans[a[i]]++;
	}
	return ;
}

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	//solve(1);
	for(int i=n;i>=1;i--){
		solve(i);
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
