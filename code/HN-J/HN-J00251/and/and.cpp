#include<bits/stdc++.h>
using namespace std;
const int N=2*1e5+5;
long long b[N],c[N]={0};
long long n,m,maxx,ans[N];//暴力出奇迹 
void AND(int dis){
	if(dis==m+1){
		maxx=max(maxx,ans[dis-1]);
		cout<<endl;
		return ;
	}
	for(int i=1;i<=n;i++){
		if(dis==1){
			ans[0]=b[i];
		}
		if(c[i]==0){
			c[i]=1;
			ans[dis]=ans[dis-1]&b[i];
			//cout<<"i为"<<i<<" "<<"ans为"<<ans[dis-1]<<" "<<"b[i]为"<<b[i]<<"maxx为"<<maxx<<"dis为"<<dis<<endl;
			AND(dis+1);
			c[i]=0;
		}
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>b[i];
	}
	if(m==n){
		int cnt=b[1];
		for(int i=1;i<=n;i++){
			cnt=cnt&b[i];
		}
		cout<<cnt;
		return 0;
	}
	if(m==n-1){
		for(int i=1;i<=n;i++){
			long long cnt=b[1];
			maxx=0;
			for(int j=1;j<=n;j++){
				if(i!=j){
					cnt=cnt&b[i];	
				}
			}
			maxx=max(maxx,cnt);
		}
		cout<<maxx;
		return 0;
	}
	if(m==1){
		maxx=0;
		for(int i=1;i<=n;i++){
			maxx=max(maxx,b[i]);
		}
		cout<<maxx;
		return 0;
	}
	if(m==2){
		long long cnt=b[1];
		for(int i=1;i<=n;i++){
			maxx=0;
			for(int j=1;j<=n;j++){
				cnt=b[i]&b[j];	
			}
			maxx=max(maxx,cnt);
		}
		cout<<maxx;
		return 0;
	}
	if(n<=20000){
		AND(1);
		cout<<maxx;
	}
    return 0;
}
/*
5 3 
31 3 1 15 7
*/
