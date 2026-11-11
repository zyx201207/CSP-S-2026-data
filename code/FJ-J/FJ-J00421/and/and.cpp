#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
long long a[N],f[50];
vector<int> g[30],p[N],q;
void init(){
	f[0]=1;
	for(int i=1;i<=30;i++){
		f[i]=f[i-1]*2;
	}
}

void solve(int x,int id){
	for(int i=30;i>=0;i--){
		if(f[i]<=x){
			x-=f[i];
			p[id].push_back(i);
			g[i].push_back(id);
		}
	}
}

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	init();
	for(int i=1;i<=n;i++){
		cin>>a[i];
		solve(a[i],i);
	}
	int l=30;
	while(g[l].size()<m && l>=0){
		l--;
	}
	if(l<0){
		cout<<0<<"\n";
		return 0;
	}
	long long ans=f[l];
	
	for(int i=0;i<g[l].size();i++){
		int x=g[l][i];
		q.push_back(x);
	}
	for(int i=l-1;i>=0;i--){//30
		queue<int> s;
		int cnt=0;
		for(int j=0;j<q.size();j++){//n
			int x=q[j];
			for(int k=0;k<p[x].size();k++){//30
				int y=p[x][k];
				if(y==i){
					s.push(x);
					cnt++;
					break;
				}
			}
		}
		if(cnt>=m){//n
			q.clear();
			ans+=f[i];
			while(s.size()){
				q.push_back(s.front());
				s.pop();
			}
		}
	}
	cout<<ans<<"\n";
	return 0;
}
