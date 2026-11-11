#include<bits/stdc++.h>
using namespace std;
int c,t,n,d,x[2000006],minn=INT_MAX,sum,ans;
void dfs(int now,int end,int len){
	if(now==end){
		int f=minn;
		minn=min(minn,len);
		if(f!=minn){
			sum=1;
		}else{
			sum++;
		}
	}
	for(int i=now+1;abs(x[i]-x[now])<=d;i++){
		if(i>end) break;
		dfs(i,end,len+1);
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				dfs(i,j,0);
				if(sum==2){
					ans++; 
//					cout<<i<<" "<<j<<endl;
				}
				minn=INT_MAX;
				sum=0;
			}
		}
		cout<<ans<<endl;
		ans=0;
	}
}
/*
这无疑是神圣的
肥美图论 
这…… 
不管了，暴力起手 
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5
*/
