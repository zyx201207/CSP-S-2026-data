#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;
#define ll long long
ll x[N];
ll n,d,t,c;
vector<ll> rout;

void dfs(int b,ll k,int e){//bianhao cishu
	if(b == e){
		rout.push_back(k);
		return;
	}
	for(int i=b+1;i<=e;i++){
		if(x[i]-x[b]<=d){
			dfs(i,k+1,e);
		}
	}
}
void deal1(){
	while(t--){
		int ans1=0;
		cin>>n>>d;
		for(int i=0;i<n;i++){
			cin>>x[i];
		}
		for(int i=0;i<n;i++){
			for(int j=i+3;j<n;j++){
				rout.clear();
				dfs(i,0,j);
				sort(rout.begin(),rout.end());
				int cnt=0;
				if(rout.size()!=0) cnt++;
				//cout<<cnt<<'\n';
				for(int k=1;k<rout.size();k++){
					//cout<<rout[k]<<' ';
					if(rout[k] == rout[k-1]){
						cnt++;
						continue;
					}
					else break;
				}
				//cout<<'\n'<<i<<' '<<j<<' '<<cnt<<'\n';
				if(cnt == 2) ans1++;
			}
		}
		cout<<ans1<<'\n';
	}
	
}
void deal2(){
	
	while(t--){
		cin>>n>>d;
		for(int i=0;i<n;i++){
			cin>>x[i];
		}
		ll dx=x[1]-x[0];
		ll kk=d/dx;
		if(dx>d || kk<2){
			cout<<0;
			continue;
		}
		ll len=kk+1;
		cout<<n-len<<'\n';
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>t;
	if(c <= 6){
		deal1();
		return 0;
	}
	if(c == 11|| c == 12){
		deal2();
		return 0;
	}
	return 0;
}
