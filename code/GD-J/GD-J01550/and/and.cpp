#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+10;
int n,m,mx=0;
int v[N][35],vv[35];
ll ans=0;
vector<int> res;
void dfs(int d){
	if(d==-1){
		return;
	}
	if(vv[d]<m){
		dfs(d-1);
		return;
	}
	int sum=res.size();
	vector<int> de;
	//2e5
	for(int i=0;i<res.size();i++){
		if(v[res[i]][d]==0){
			de.push_back(i);
			sum--;
		}
	}
	if(sum>=m){
		for(int i=de.size()-1;i>=0;i--){
			res.erase(res.begin()+de[i]);
		}
		ans+=pow(2,d);
	}
	dfs(d-1);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	//2e5long2e5
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		int cnt=0;
		while(x){
			if(x%2==1){
				mx=max(mx,cnt);
				v[i][cnt]++;
				vv[cnt]++;
			}
			cnt++;
			x>>=1;
		}
	}
	for(int i=mx;i>=0;i--){
		if(vv[i]>=m){
			mx=i;
			ans+=pow(2,i);
			for(int i=1;i<=n;i++){
				if(v[i][mx]==1){
					res.push_back(i);
				}
			}
			//30
			dfs(mx-1);
			break;
		}
	}
	printf("%lld",ans);
	return 0;
}
