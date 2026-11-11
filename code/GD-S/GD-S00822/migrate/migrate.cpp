#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,T=1;
int n,d,ans;
void init(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
}
int x[2000001];
pair<int,int> mi[5001][5001];
struct az{
	int wz,sz; 
};
queue<az>q;
void tp(int ch){
	if(ch>d || ch*2>d){
		cout<<"0\n";
		return ;
	}
	int jg=d/ch;
	if(jg==1){
		cout<<"0\n";
	}
}
void solve(){
	cin>>n>>d;
	ans=0;
	bool pddc=1,ky=0;
	for(int i=1;i<=n;i++){
		cin>>x[i];
		if(i>=2 && x[i]-x[i-1]<=d){
			ky=1;
		}
	}
	if(n<=3 || !ky){
		cout<<"0\n";
		return ;
	}
	for(int i=3;i<=n;i++){
		if(x[i]-x[i-1]!=x[2]-x[1]){
			pddc=0;
			break;
		}
	}
	if(pddc){
		tp(x[2]-x[1]);
	}
	for(int i=1;i<=5000;i++){
		for(int j=1;j<=5000;j++){
			mi[i][j].first=1e9;
			mi[i][j].second=0;
		}
	}
	for(int i=1;i<=n;i++){
		q.push({i,0});
		while(!q.empty()){
			az w=q.front();
			q.pop();
			for(int j=w.wz+1;j<=n;j++){
				if(x[j]-x[w.wz]<=d){
					if(mi[i][j].first==w.sz+1){
						mi[i][j].second++;
						q.push({j,w.sz+1});
					}
					else{
						if(mi[i][j].first>w.sz+1){
							mi[i][j].first=w.sz+1,mi[i][j].second=1;
							q.push({j,w.sz+1});
						}
						else{
							continue;
						}
					}
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(mi[i][j].second==2){
				ans++;
			}
		}
	}
	cout<<ans<<"\n";
	return;
}
signed main(){
	init();
	cin.tie(nullptr),cout.tie(nullptr),ios::sync_with_stdio(false);
	cin>>c>>T;
	while(T--){
		solve();
	}
	return 0;
}
