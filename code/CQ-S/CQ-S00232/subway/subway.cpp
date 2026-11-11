#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5*1e4+1;
const int INF=1e18;
int n,m;
int test;
int testt;
int q;
int w[N];
struct stu{
	int r;
	int t;
};
int sz[505];
vector<int>ro[N];
vector<int>road[501];
int t[N][501];
int spfa(int st,int ed){
	queue<int>q;
	vector<int>s(n+1,INF);
	vector<bool>f(n+1,0);
	s[st]=0;
	f[st]=1;
	q.push(st);
	while(!q.empty()){
		int z=q.front();
		q.pop();
		f[z]=0;
		for(int k:ro[z]){
			for(auto i:road[k]){
				if(i==z)continue;
				if(s[i]>s[z]+t[k][z]+t[k][i]){
					s[i]=s[z]+t[k][z]+t[k][i];
					if(!f[i]){
						q.push(i); 
					}
				}
			}
		} 
	}
	return s[ed];
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>test>>m>>n>>testt>>q;
	for(int i=1;i<=n;i++){
		cin>>w[i];
	}
	for(int k=1;k<=m;k++){
		cin>>sz[k];
		for(int i=1;i<=sz[k];i++){
			int r,tt;
			cin>>r>>tt;
			ro[r].push_back(k); 
			road[k].push_back(r);
			t[k][r]=tt;
		}
	}
	while(q--){
		int l,r;
		cin>>l>>r;
		int ans=w[l]+w[r]+spfa(l,r);
		cout<<ans<<endl;
	}
    return 0;
}
	
