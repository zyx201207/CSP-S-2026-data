#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+10;
int C,T,n,d,a[N],ans_i,ans;
int op;
void dfs(int now,int r,int step){
	if(now>=r){
		if(step<ans_i){
			ans_i=step;
			ans=1;
		}else if(ans_i==step)ans++;
		return;
	}
	int r_w=a[now]+d;
	if(r_w>=a[r])dfs(r,r,step+1);
	else{
		for(int i=now+1;a[i]<=r_w;i++){
			dfs(i,r,step+1);
		}	
	}
}
void task1(){
	while(T--){
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>a[i];
		if(n<=3)cout<<"0\n";
		int answer=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				ans=0;
				ans_i=INT_MAX;
		//		if(i==1&&j==4)op=1;
				dfs(i,j,0);
				op=0;
				if(ans==2)answer++;
			}
		}
		cout<<answer<<endl;
	}
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>C>>T;
	task1();
}
