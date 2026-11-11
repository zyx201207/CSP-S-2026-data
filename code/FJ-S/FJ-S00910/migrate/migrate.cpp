#include<bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;
ll c,t,n,d,x[2000010],sum=LLONG_MAX,s=0,ss=0;
void dfs(int xx,int en,int step){
	//cout<<xx<<" "<<en<<" "<<step<<endl;
	//_sleep(100);
	if (xx==en){
		if (step<sum){
			sum=step;
			ss=0;
		}else{
			ss++;
		}
		return;
	}
	for (int i=xx+1;x[i]-x[xx]<=d&&i<=en;i++) dfs(i,en,step+1);
	//cout<<endl;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while (t--){
		s=0;
		cin>>n>>d;
		bool tp1=1;
		for (int i=1;i<=n;i++){
			cin>>x[i];
			if (i>2&&x[i]-x[i-1]!=x[i-1]-x[i-2]) tp1=0;
		}
		if (tp1==1){
			if (d>=2*x[2]-2*x[1]&&d<3*x[2]-3*x[1]) cout<<(n-2)*(n-3)<<endl;
			continue;
		}
		for (int i=1;i<=n;i++) for (int j=i+1;j<=n;j++){
			sum=LLONG_MAX,ss=0;
			dfs(i,j,0);
			if (ss==1) s++;
		}
		cout<<s<<endl;
	}
	return 0;
} 
/*
*/
