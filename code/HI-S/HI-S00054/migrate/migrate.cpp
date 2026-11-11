#include<bits/stdc++.h>
using namespace std;
int c,t,x[2000005],cnt=0,d,n,a[100005];
void dfs(int s,int b,int cnt1){
	if(s==b){
		a[++cnt]=cnt1;
	}
	for(int l=s+1;l<=b;l++){
		if(x[l]-x[s]<=d){
			dfs(l,b,cnt1+1);
		}else{
			break;
		}
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		memset(x,0,sizeof(x));
		memset(a,0,sizeof(a));
		cin>>n>>d;
		int ans=0;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=2;j<=(n-i);j++){
				cnt=0;
				dfs(i,i+j,0);
				if(cnt==2){
					cout<<i<<" "<<i+j<<endl;
					ans++;
				}
			}
		}
		cout<<ans-1<<"\n";
	}
	return 0;
}
