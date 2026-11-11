#include<bits/stdc++.h>
using namespace std;
long long c,t;
long long a[2000005];
vector<int> via;
bool flag=0;
long long minans=INT_MAX;
long long mincnt=0;
void dfs(long long st,long long ed,long long d){
	if(st==ed){
		//~ for(int x:via){
			//~ cout<<x<<' ';
		//~ }
		//~ cout<<endl;
		long long aans=via.size();
		//~ cout<<minans<<' '<<aans<<endl;
		if(aans==minans&&mincnt==1){
			flag=1;
			mincnt++;
			//~ cout<<minans<<endl;
		}
		else{
			if(aans<=minans){
				minans=aans;
				mincnt=1;
				flag=0;
			}
		}
		return;
	}
	for(long long i=st+1;i<=ed;i++){
		if(a[i]-a[st]<=d){
			via.push_back(i);
			dfs(i,ed,d);
			via.pop_back();
			
		}
	}
}
bool check(long long x,long long y,long long d){
	if(y-x<=1) return 0;
	via.clear();
	via.push_back(x);
	flag=0;
	minans=INT_MAX;
	mincnt=0;
	dfs(x,y,d);
	if(flag){
		return 1;
	}
	return 0;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--){
		long long n,d,ans=0;
		cin>>n>>d;
		for(long long i=1;i<=n;i++){
			cin>>a[i];
		}
		for(long long i=1;i<=n;i++){
			for(long long j=1;j<=n;j++){
				if(i==j){
					continue;
				}
				if(check(i,j,d)){
					ans++;
					//~ cout<<i<<' '<<j<<"yy"<<endl;
				}
			}
		}
		cout<<ans<<endl;
		//~ via.push_back(1);
		//~ dfs(1,4,2);
		//~ cout<<flag;
	}
	return 0;
}
