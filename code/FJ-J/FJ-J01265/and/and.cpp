#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m;
long long a[N],p[35],cnt[35],sum;
bool t[N][35],ans[35];
vector<int> b[35];
void dfs(vector<int> v,int w){
	ans[w]=1;
	if(!w) return;
	for(int i=w-1;i>=0;i--){
		if(cnt[i]>=m){
			int count=0;
			vector<int> k;
			k.clear();
			for(int j=0;j<v.size();j++){
				int u=v[j];
				if(t[u][i]) count++,k.push_back(u);
			}
			if(count>=m){
				dfs(k,i);
				break;
			}
		}
		
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	p[0]=1;
	for(int i=1;i<=30;i++) p[i]=(p[i-1]<<1);
	for(int i=1;i<=n;i++){
		cin>>a[i];
		for(int j=30;j>=0;j--){
			if(a[i]>=p[j]&&((a[i]>>j)&1)){
				a[i]-=p[j];
				b[j].push_back(i);
				t[i][j]=1;
				cnt[j]++;
			}
		}
	}
	for(int i=30;i>=0;i--){
		if(cnt[i]>=m){
			dfs(b[i],i);
			break;
		}
	}
	for(int i=0;i<=30;i++) if(ans[i]) sum+=p[i];
	cout<<sum;
	return 0;
}
