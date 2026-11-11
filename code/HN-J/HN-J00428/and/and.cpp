#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int N=2e5+25;
int n,m;
int a[N],vis[N];
queue<int>q;
void solve(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		q.push(a[i]);
	}
	int p=1;
	for(int i=1;i<=32;i++){
		p*=2;
	}
	for(int i=32;i>=1;i--){
		int o=q.size();
		int s1=0,s2=0;
		while(o--){
			int f=q.front();
			q.pop();
			if(f/p>0)s1++;
			else s2++;
			q.push(f);
		}
		if(s1>=s2&&s1>=m){
			o=q.size();
			while(o--){
				int f=q.front();
				q.pop();
				if(f/p>0){
					q.push(f);
				}
			}
		}
		if(s1==m)break;
		p/=2;
	}
	if(q.size()==m){
		int x=q.front();
		for(int i=1;i<=m;i++){
			int f=q.front();
			x&=f;
			q.pop();
		}
		cout<<x;
	}
	else{
		int o=0;
		while(q.size()){
			int f=q.front();
			vis[++o]=f;
			q.pop();
		}
		sort(vis+1,vis+o+1);
		for(int i=o-m+1;i>=1;i--){
			int x=vis[i],sum=0;
			for(int j=i;j<=o;j++){
				int y=vis[j];
				if((x&y)==x)sum++;
				if(sum>=m)break;
			}
			if(sum>=m){
				cout<<x;
				return;
			}
		}
		cout<<0;
	}
	return ;
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--){
		solve();
	}
	return 0;
}
