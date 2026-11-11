#include<bits/stdc++.h>
using namespace std;
long long a[200005];
long long mem [200005];
int n,m;
long long maxx=-1e9;
long long dfs(long long x,long long sum,long long id){
	if(x==0)return sum;
	if(mem[x]!=-1)return mem[x];
	sum=a[id];
	for(int i=id+1;i<n;i++){
		sum=dfs(x-1,sum&a[i],i);
		maxx=max(maxx,sum);
	//	long long res=sum;
	//	mem[x]=res;
	//	return res;
	}
	long long res=maxx;
	mem[id]=res;
	maxx=-1e9;
	//dfs(x-1,sum,id++);
	return res;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);	
	cin>>n>>m;
	memset(mem,-1,sizeof(mem));
	for(int i=0;i<n;i++){
		cin>>a[i];
		//cout<<mem[i]<<" ";
	}
	cout<<dfs(n-1,a[0],0);
	//cout<<mem[m];
	//cout<<mem[m];
	return 0;
}
