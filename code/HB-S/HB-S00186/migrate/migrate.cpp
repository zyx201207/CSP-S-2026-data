#include <bits/stdc++.h>
using namespace std;
long long c,t,n,d,a[2000005],minn=1e9,book[2000005];
void dfs(long long x,long long y,long long step){
	if(x==y){
		minn=min(minn,step);
		book[step]++;
		return ;
	}
	if(x>y)return ;
	for(int i=x+1;i<=y;i++){
		if(a[i]-a[x]<=d){
			dfs(i,y,step+1);
		}
		else return ;
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>a[i];
		int cnt=0;
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				minn=1e9;
				memset(book,0,sizeof(book));
				dfs(i,j,1);
				if(minn==1e9)break;
				if(book[minn]==2){
					cnt++;
				}
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
}
