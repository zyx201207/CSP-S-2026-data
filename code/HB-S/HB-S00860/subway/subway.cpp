#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,a[114514],h=1;
long long diss[50005];
struct node{
	long long st,dis;
};
priority_queue< vector<node>,greater<node> > que;
bool book[50005];
node y[114514];
vector<node> mapp[50005];


int main(){
	cin>>c>>n>>m>>d>>q;
	memset(diss,0x3f,sizeof diss);
	diss[1]=0;
	for(int i=1;i<=m;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		long long u;
		cin>>u;
		for(int j=1;j<=u;j++){
			
			cin>>y[j].st>>y[j].dis;
		}
		for(int j=1;j<=u-1;j++){
			for(int k=j+1;k<=u;k++){
				node x;
				x.st=y[k].st;
				x.dis=y[j].dis+y[k].dis;
				mapp[y[j].st].push_back(x);
			}
		}
	}
	
	while(q--){
		long long l,s;
		cin>>l>>s;
		memset(diss,0,sizeof diss);
	}
	return 0;
}
