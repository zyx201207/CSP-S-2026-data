#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e6+10;
int a[N],sum,ans,n,d;
void dfs(int start,int end,int step){
	if(start==end){
		if(step==ans) sum++;
		return ;
	}
	if(step>=ans) return ;
	for(int i=start;i<=end;i++){
		if(a[i]-a[start]>d) break;
		dfs(i,end,step+1);
	}
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int c,t;
	cin>>c>>t;
	while(t--){
		int cnt=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++)
			cin>>a[i];
		int ttt=a[2]-a[1]; 
		bool flag=true;
		for(int i=3;i<=n;i++)
			if(a[i]-a[i-1]!=ttt) flag=false;
		if(flag==true){
			if(ttt>d) cout<<0<<"\n";
			else{
				for(int i=1;i<=n;i++){
					for(int j=i+1;j<=n;j++){
						if(a[j]-a[i]<=d) continue;
						ans=(a[j]-a[i]+1)/d;
						dfs(i,j,0);
						if(sum==2) cnt++;
						sum=0;
					}
				}
				cout<<cnt<<"\n";
			}
		}
		else{
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					if(a[j]-a[i]<=d) continue;
					ans=(a[j]-a[i]+1)/d;
					dfs(i,j,0);
					if(sum==2) cnt++;
					sum=0;
				}
			}
			cout<<cnt<<"\n";
		}
	}
	return 0;
}

