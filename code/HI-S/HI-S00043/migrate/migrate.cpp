#include<bits/stdc++.h>
using namespace std;
using ll=long long;
/*最多n(n-1)/2对岛屿，如何验证？
bfs？*/
const int N=2E6+10;
int n;
ll d,x[N];
ll sA(){
	//有什么性质？
	//设a[l]与a[r]距离 最接近且不大于d
	//那么l到2r仅有一条路径吗？
	ll minus=x[2]-x[1];
	if(d<=minus)
		return 0;
	return 1ll*n-(d/minus)*2+1;
}ll sB(){
	bool vis[N];
	memset(vis,0,sizeof(vis));
	int p=1;
	for(int i=1;x[i]-x[1]<=d;i++)
		p=i;
	if(p==n||p==1)
		return 0;
	int l=1,r=p+1,res=0;
	//r表示目前待测的右侧端点，l表示目前左侧最远起点
	//不难发现l单调不减
	for(int i=r;i<=n;i++){
		while(x[i]-x[l]>d)
			l++;
		if(p-l==1){
			res++;
			vis[i]=1;
		}
	}l=p-1,r=n;
	for(int i=l;i>=1;i--){
		while(x[r]-x[i]>d)
			r--;
		if(r-p==1&&!vis[r])
			res++;
	}return res;
}int main(){
	ios::sync_with_stdio(0);
	ifstream fin("migrate.in");
	ofstream fout("migrate.out");
	int c,t;
	fin>>c>>t;
	while(t--){
		fin>>n>>d;
		memset(x,0,sizeof(x));
		for(int i=1;i<=n;i++)
			fin>>x[i];
		if(n<3||x[n]-x[1]<=d){
			fout<<0<<endl;
			continue;
		}if(c==11||c==12)
			fout<<sA()<<endl;
		else if(c==13||c==14)
			fout<<sB()<<endl;
	}return 0;
}

