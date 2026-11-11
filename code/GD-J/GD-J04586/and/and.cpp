#include <bits/stdc++.h>
using namespace std;
const int N=200010;
int n,m;
int a[N];
int ans=0;
bool cmp(int x,int y){
	return x>y;
}
void dfs(int id,int num,int jishu){
	if(id>n and jishu==m){
		ans=max(ans,num);
		return ;
	}
	if(id>n) return ;
	dfs(id+1,num&a[id],jishu+1);dfs(id+1,num,jishu);
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	int maxx=-1;
	cin>>a[1];
	maxx=max(maxx,a[1]);
	int temp=a[1];
	for(int i=2;i<=n;i++){
		cin>>a[i];
		maxx=max(maxx,a[i]);
		temp&=a[i];
	}
	if(m==1){
		cout<<maxx<<endl;
	}else if(m==n){
		cout<<temp<<endl;
	}else if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i==j) continue;
				ans=max(ans,a[i]&a[j]);
			}
		}
		cout<<ans<<endl;
	}else if(m==n-1){
		sort(a+1,a+n+1);
		int temp=a[2];
		for(int i=3;i<=n;i++){
			temp&=a[i];
		}	
		cout<<temp<<endl;
	}else{
		dfs(1,INT_MAX,0);
		cout<<ans<<endl;
	}
	return 0;
	fclose(stdin);
	fclose(stdout);
}
