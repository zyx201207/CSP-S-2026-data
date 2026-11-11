#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,a[1001][1001],w[100001];
bool book[10001],book2[10001];
long long minn;
void dfs(int s,int e,int summ){
	if(s==e){
		if(minn>summ+w[s]){
			minn=summ+w[s];
		}
		return;
	}else{
		for(int i=1;i<=n;i++){
			if(a[i][s]==0 || book2[i])continue;
			book2[i]=true;
			for(int j=1;j<=m;j++){
				if(a[i][j]!=0 && !book[j] && s!=j){
					book[j]=true;
					dfs(j,e,summ+a[i][s]+a[i][j]);
					book[j]=false;
				}
			}book2[i]=false;
	}
	}return;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}for(int i=1;i<=n;i++){
		cin>>a[i][0];
		for(int j=1;j<=a[i][0];j++){
			int xxx,yyy;
			cin>>xxx>>yyy;
			a[i][xxx]=yyy;
		}
	}for(int i=1;i<=q;i++){
		minn=0x7ffffff;
		int s,e;
		cin>>s>>e;
		for(int j=1;j<=m;j++){
			book[j]=false;
			book2[j]=false;
		}
		book[s]=true;
		dfs(s,e,w[s]);
		book[s]=false;
		cout<<minn;
	}fclose(stdin);
	fclose(stdout);
	return 0;
}
