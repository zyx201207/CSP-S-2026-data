#include<bits/stdc++.h>
using namespace std;
int x[2000010],n,d,ans=1e9,res=1,t,c,r=0;
void dfs(int a,int b,int cnt){
	if(a==b){
		if(cnt==ans)res++;
		if(cnt<ans)res=1;
//		cout<<cnt<<endl;
		ans=min(ans,cnt);
		return;
	}
	if(a>b)return;
	for(int i=1;x[a+i]-x[a]<=d;i++){
		
		dfs(a+i,b,cnt+1);
			
		
	}
}
void solve(){
	r=0;
	cin>>n>>d;
	int l=1;
	for(int i=1;i<=n;i++){
		cin>>x[i];
	}
//	if(n>5){
//		int ff=x[2]-x[1]
//		for(int i=2;i<=n;i++){
//			if(x[i]-x[i-1]!=ff){
//				l=0;
//				break;
//			}
//		}
//		if(l){
//			int cc=d/ff;
//			
//		}
//	}
	for(int i=1;i<=n;i++){
		for(int j=i+2;j<=n;j++){
			res=1;
			ans=1e9;
			dfs(i,j,0);
			
			if(res==2)r++;
		}
	}
	cout<<r<<endl;

}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)solve();
	return 0;
} 
