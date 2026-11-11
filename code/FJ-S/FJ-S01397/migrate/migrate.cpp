#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[2000005];
int minlen[2000005];
int mingo[2000005];
int n,l;
void dfs(int idx,int step){
//	cout<<"现在正在判断第"<<idx<<"个点走了"<<step<<"步"<<endl; 
	if(step>minlen[idx]){
		return;
	}
	if(step<minlen[idx]){
		return;
	}
	if(step==minlen[idx]){
//		cout<<"第"<<idx<<"个点增加一条最短路"<<endl; 
		mingo[idx]++;
	}
	for(int i=idx+1;i<=n;i++){
		if(i>=1&&i<=n&&a[i]-a[idx]<=l&&step+1<=minlen[i]){
//			cout<<i<<"可以从"<<idx<<"走过来";
//			cout<<i<<"走了"<<step+1<<"步"<<endl; 
			dfs(i,step+1);
		}
	}
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int xxx,T;
	cin>>xxx>>T;
	while(T--){
		memset(minlen,-1,sizeof(minlen));
		memset(a,-1,sizeof(minlen));
		memset(mingo,0,sizeof(mingo));
		cin>>n>>l;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		queue <int> q;
		q.push(1);
		minlen[1]=0;
		while(!q.empty()){
			int tmp=q.front();
			q.pop();
			for(int i=tmp+1;i<=l+tmp;i++){
				if(i>=1&&i<=n&&minlen[i]==-1&&a[i]-a[tmp]<=l){
					q.push(i);
					minlen[i]=minlen[tmp]+1;
				}
			}
		}
//		for(int i=1;i<=n;i++){
//			cout<<minlen[i]<<" ";
//		}
//		cout<<endl;
		dfs(1,0);
		int cnt=0;
		for(int i=1;i<=n;i++){
//			cout<<"第"<<i<<"个点有"<<mingo[i]<<"条最短路径"<<endl;
			if(mingo[i]==2){
				cnt++;
			}
		}
//		cout<<endl;
		cout<<cnt<<endl;
	}
	return 0;
}
