#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <queue>
#include <vector>
#include <cstring>

#define N 2000005

using namespace std;

int c,t,n,minans;
long long d,a[N],dp[N]; 

int ans,to;
void dfs1(int x,int step){
	if(x==to){
		minans=min(minans,step);
		return;
	} 
	if(x>to) return;
	for(int i=x+1;i<=n;i++){
		if(a[i]-a[x]>d) break;
		dfs1(i,step+1);
	}
}
void dfs2(int x,int step){
	if(x==to){
		if(step==minans)ans++;
		return;
	} 
	if(x>to) return;
	for(int i=x+1;i<=n;i++){
		if(a[i]-a[x]>d) break;
		dfs2(i,step+1);
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		if(n==1){
			cout<<"0\n";
			continue;
		} 
		for(int i=1;i<=n;i++) cin>>a[i];
		if(a[n]-a[1]<=d){
			cout<<"0\n";
			continue;
		}
		long long gc=a[2]-a[1];
		bool f=0;
		for(int i=3;i<=n;i++){ 
			if(a[i]-a[i-1]!=gc){
				f=1;
				break;
			}
		}
		if(f==0){
			if(d!=2){
				cout<<"0\n";
				continue;
			}
			else{
				cout<<max(0,n-3)<<'\n';
				continue;
			}
		}
		else{
			int cnt=0;
			for(int i=1;i<n;i++){
				for(int j=i+1;j<=n;j++){
					ans=0;
					to=j;
					minans=0x3f3f3f3f;
					dfs1(i,0);
					dfs2(i,0);
					if(ans==2){
						cnt++;
					}
				}
			}
			cout<<cnt<<'\n';
		}
	}
	return 0;
}
