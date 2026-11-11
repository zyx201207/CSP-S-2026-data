#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500010],Answer=0;
map<long long,long long> b;
void DFS(int x,long long Counter){
	if(x>=n){
		long long js=1;
		for(int i=1;i<=n;i++){
			js=max(js,b[a[i]]);
		}
		Answer=max(Answer,js);
		return;
	}
	if(Counter>=(a[x+1]-a[x])*b[x]){
		int y=a[x+1]-a[x];
		a[x]+=y;
		b[a[x+1]]+=b[x];
		DFS(x+1,Counter-y);
		a[x]-=y;
		b[a[x+1]]-=b[x];
	}
	DFS(x+1,Counter);
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	a[n+1]=1e18;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[a[i]]++;
	}
	sort(a+1,a+1+n);
	DFS(1,m);
	cout<<Answer;
}
