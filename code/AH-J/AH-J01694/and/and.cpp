#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
const int N=200005;
int a[N],n,m,p[N];
ull ans=0;
void solve(int d,ull s){
	if(d==m){
		if(s>ans)ans=s;
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(p[i])continue;
		p[i]=1;
		solve(d+1,s&a[i]);
		p[i]=0;
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		p[i]=1;
		solve(1,a[i]); 
		p[i]=0;
	}
	cout<<ans;
	return 0;
}
