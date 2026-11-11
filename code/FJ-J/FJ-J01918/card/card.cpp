#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define INF 0x3f3f3f3f3f3f3f3f
using pii = pair<int,int> ;
int n,m,a[500100],ans[300100];
bool st[300100];
void p(){
	for(int i=1;i<=n;i++){
		if(a[i]!=a[n])ans[1]++,ans[2]++;
		else ans[a[n]]++;
	}
	cout<<ans[1]<<" "<<ans[2];
	return ;
}
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(m==1){
		cout<<n;
		return 0;
	}
	else if(m==2){
		p();
		return 0;
	}
	for(int i=1;i<=n;i++){
		vector<int>v;
		for(int j=1;j<=m;j++)st[j]=0;
		for(int j=i;j<=n;j++){
			if(st[a[j]])
				while(v.size()&&v[v.size()-1]!=a[j])
					st[v[v.size()-1]]=0,v.pop_back();
			else {
				st[a[j]]=1;
				v.push_back(a[j]);
			}
		}
		for(auto j:v){
			ans[j]++;
//			cout<<j<<' ';
		}
//		cout<<endl;
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	} 
	return 0;
}
/*
4 3
1 2 1 3
10 3
3 1 2 1 3 2 3 1 2 1
*/
