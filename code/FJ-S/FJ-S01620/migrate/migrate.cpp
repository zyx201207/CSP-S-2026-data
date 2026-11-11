#include<bits/stdc++.h>
using namespace std;
int a[2020],c,d,ans[2020],really_ans=0;
int n;
void dfs(int deep,int last){
	ans[deep]++;
	if(last==n){
		return;
	}
	for(int i=last+1;i<=n;i++){
		if(a[i]-a[last]<=d){
			dfs(deep+1,i);
		}else break;
	}
	return;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c;
	int T;
	cin>>T;
	while(T--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int j=1;j<=n;j++){
			memset(ans,0,sizeof ans);
			dfs(0,j);
			for(int i=1;i<=n;i++){
				if(ans[i]==2) really_ans++;
			}
		} 
		cout<<really_ans/2;
	}
}
