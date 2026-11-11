#include<bits/stdc++.h>
using namespace std;
#define int long long

int d,n;
int arr[2000005];
int stp[2000005];
int ans[2000005];

int bfs(int st){
	for(int i=st;i<=n;i++){
		stp[i]=INT_MAX;
		ans[i]=0;
	}
	queue<int> q;
	queue<int> p;
	q.push(st);
	p.push(0);
	stp[st]=0;
	ans[st]=1;
	while(!q.empty()){
		int u=q.front();
		int stp0=p.front();
		q.pop();
		p.pop();
		for(int i=u+1;i<=n&&arr[i]-arr[u]<=d;i++){
			if(stp[i]==stp0+1){
				ans[i]+=ans[u];
				q.push(i);
				p.push(stp0+1);
			}
			if(stp[i]>stp0+1){
				stp[i]=stp0+1;
				ans[i]=ans[u];
				q.push(i);
				p.push(stp0+1);
			}
		}
	}
	int res=0;
	for(int i=st;i<=n;i++){
		if(ans[i]==2){
			res++;
		}
	}
	return res;
}

signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int c,t;
	cin >> c >> t;
	while(t--){
		cin >> n >> d;
		for(int i=1;i<=n;i++){
			cin >> arr[i];
		}
		int tmp=0;
		for(int i=1;i<=n;i++){
			tmp+=bfs(i);
		}
		cout << tmp << endl;
	}
	return 0;
}
//FUCK CCF
