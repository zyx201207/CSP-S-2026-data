#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500005];
long long ans[500005];
long long OUT[300005];
long long b[300005];
bool bb[500005];
vector<long long> e[500005];
stack<long long> st;
void dfs(long long x,long long fa){
//	cout<<x<<' '<<fa<<endl;
	for(long long i=0;i<e[x].size();i++){
		if (e[x][i]!=fa){
//			cout<<x<<"->"<<e[x][i]<<endl;
			dfs(e[x][i],x);
		} 
	}
	for(long long i=0;i<e[x].size();i++){
		if (e[x][i]!=fa) ans[x]+=ans[e[x][i]];
	}
	ans[x]++;return;
}
int main(){
	freopen("card.in","r",stdin);
//	freopen("card6.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	b[a[n]]=n;bb[n]=true;
	for(long long i=n-1;i>=1;i--){
		if (b[a[i]]!=0){
			e[i].push_back(b[a[i]]);
			e[b[a[i]]].push_back(i);
			b[a[i]]=i;
		}else{
			e[i].push_back(i+1);
			e[i+1].push_back(i);
			bb[i]=true;b[a[i]]=i;
		}
	}
	dfs(n,0);
	for(long long i=1;i<=n;i++){
		if (bb[i]==true) OUT[a[i]]+=ans[i];
	}
//	for(long long i=1;i<=n;i++)cout<<ans[i]<<' ';cout<<endl;
	for(long long i=1;i<=m;i++){
		cout<<OUT[i]<<' ';
	}
	return 0;
}
