#include<bits/stdc++.h>
#define endl "\n"
#define int long long 
using namespace std;
struct node{
	int l,r;
};
int n,m;
int a[500010];
node qj[500010];
int saf[500010];
int tim[500010];
int cf[500010];//用于更新safety的差分数组 (后者覆盖前者)
int safety[500010];//编号为i 的纸牌的安全区间编号 
int ans[300010];//答案
vector<int>e[300010];
bool cmp(node a,node b){
	return a.r-a.l+1>b.r-b.l+1;
}
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	bool flag=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<n;i++){
		if(a[i]>a[i+1]){
			flag=0;
		}
	}
//	for(int i=1;i<=n;i++){
//		cout<<a[i]<<" ";
//	}
	for(int i=1;i<=n;i++){
		e[a[i]].push_back(i);
	}
	int ss=0;
	for(int i=1;i<=m;i++){
		for(int j=1;j<e[i].size();j++){
			qj[++ss]={e[i][j-1]+1,e[i][j]-1};
		}
	}
//	for(int i=1;i<=m;i++){
//		cout<<i<<":"<<endl;
//		for(int j=0;j<e[i].size();j++){
////			qj[++ss]={e[i][j-1]+1,e[i][j]-1};
//			cout<<e[i][j]<<" ";
//		}
//		cout<<endl;
//	}
	sort(qj+1,qj+ss+1,cmp);
	for(int i=n;i>=1;i--){
		if(tim[a[i]])continue;
		tim[a[i]]=i;
	}
//	for(int i=1;i<=m;i++){
//		cout<<tim[i]<<" ";
//	}
//	cout<<endl;
	if(flag){
		for(int i=1;i<=m;i++){
			cout<<tim[a[i]]<<" ";
		}
		return 0;
	}
	for(int i=1;i<=ss;i++){
		int ll=cf[qj[i].l-1],rr=cf[qj[i].r];
//		cf[qj[i].l]=i-cf[qj[i].l-1];
		cf[qj[i].l]=i-ll;
//		cf[qj[i].r+1]=cf[qj[i].r]-i;
		cf[qj[i].r+1]=rr-i;
	}
	for(int i=1;i<=n;i++){
		safety[i]=safety[i-1]+cf[i];
	}
//	for(int i=1;i<=n;i++){
//		cout<<cf[i]<<" ";
//	}
//	cout<<endl;
//	for(int i=1;i<=n;i++){
//		cout<<safety[i]<<" ";
//	}
//	cout<<endl;
	for(int i=1;i<=m;i++){
		if(safety[i]){
			cout<<qj[safety[tim[i]]].r-qj[safety[tim[i]]].l+1<<" ";
		}else{
			cout<<tim[i]<<" ";
		}
	}
	cout<<endl;
	return 0;
}
//1 10-2 -1
//最后一张点数为i的纸牌，最小且最近的两面包夹芝士长度：开区间 
