#include<bits/stdc++.h>
using namespace std;//luogunameA_as
const int N=1e4+1;
int w[N];
vector<pair<int,int>> subhave[N];//time,lineuid
struct node{
	int k;
	vector<pair<int,int>> sub;//subuid,time
};
long long ti[N][N];
//bool const operator()(const pair<int,int> x,const pair<int,int>y){
//	return x.first>y.first;
//}
node line[501];
/*auto*/int read(){
	char c=getchar_unlocked();
	/*auto*/int sum=0;
	int f=1;
	while(c>'9'||c<'0'){
		if(c=='-') f=-1;
		c=getchar_unlocked();
	}
	while(c>='0'&&c<='9'){
		sum*=10;
		sum+=c-'0';
		c=getchar_unlocked();
	}
	return sum*f;
}
void write(/*auto*/int sum){
	int s=-1;
	char c[20];
	if(sum<0){
		sum=-sum;
		putchar_unlocked('-');
	}
	if(sum==0){
		putchar_unlocked('0');
		return ;
	}
	while(sum!=0){
		c[++s]=sum%10+'0';
		sum/=10;
	}
	for(int i=s;i>=0;i--) putchar_unlocked(c[i]);
}
int main(){/* the first idea:dijkstra(priority_queue),n^2logn,emm...I forget  how to write the third priority*/
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c=read(),n=read(),m=read(),d=read(),q=read();
	for(int i=1;i<=m;i++){
		w[i]=read();
		for(int j=1;j<=m;j++){
			ti[i][j]=INT_MAX;
		}
	}
	for(int i=1;i<=n;i++){
		 line[i].k=read();
		 for(int j=1;j<=line[i].k;j++){
			int aya=read();
			int kkk=read();
			subhave[aya].push_back({kkk,i});
			line[i].sub.push_back({aya,kkk});
		 }
	}
	// begin to dijkstra
	for(int i=1;i<=m;i++){
		queue<pair<int,int>> qp;
		qp.push({i,0});
		ti[i][i]=0;
		for(int j=i-1;j>=1;j--){
			qp.push({j,ti[i][j]});
		}
		while(!qp.empty()){
			auto qq=qp.front();
			qp.pop();
			if(ti[i][qq.first]<qq.second&&qq.first!=i) continue;
			for(auto v:subhave[qq.first]){
				for(auto val:line[v.second].sub){
					if(val.first<=i) continue;
					if(ti[i][val.first]>ti[i][qq.first]+v.first+val.second){
						ti[val.first][i]=ti[i][val.first]=ti[i][qq.first]+v.first+val.second;
						qp.push({val.first,ti[i][val.first]});
					}
				}
			}
		}
	}
	while(q--){
		int from=read();
		int to=read();
		write(ti[from][to]+w[from]+w[to]);
		putchar_unlocked('\n');
	}
	return 0;
}
