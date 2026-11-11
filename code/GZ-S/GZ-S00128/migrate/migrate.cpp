//GZ-S00128 贵阳市第一中学 赵志杰
#include <bits/stdc++.h>
using namespace std;
const int MAXN=5005,N=2e9+5;
int c,t,n,d,ans,s;
int a[MAXN][MAXN],si[MAXN];
vector<int> a1[MAXN];
void dfs(int now,int tar,int l,int l1){
	if(l1>l)return;
	if(s>=3)return;
	if(s>=3)return;
	for(int i=0;i<n;i++){
		if(a[now][i]==N)continue;
		if(i==tar && l1+1==l){
			s++;
			return;
		}
		dfs(i,tar,l,l1+1);
	}
	return;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d %d",&c,&t);
	//if(c==0)return 0;
	while(t--){
		vector<int> a1[MAXN];
		int x[MAXN];
		scanf("%d %d",&n,&d);
		if(n==1){
			printf("0\n");
			continue;
		}
		for(int i=0;i<n;i++){
			scanf("%d",&x[i]);
		}
		for(int i=0;i<n;i++){
			for(int j=0;j<n-i;j++){
				if(i==j){
					a[i][j]=0;
					continue;
				}
				
				if(x[max(i,j)]-x[min(i,j)]<=d){
					a[i][j]=1;
					a[j][i]=1;
					a1[i].push_back(j);
					a1[j].push_back(i);
				}
			}
		}
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				for(int k=0;k<n;k++){
					a[i][j]=min(a[i][j],a[i][k]+a[k][j]);
				}
			}
			si[i]=a1[i].size();
		}
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				if(a1[i].size()==0 || a1[j].size()==0 || i==j)continue;
				dfs(i,j,a[i][j],0);
				if(s==2)ans++;
				s=0;
			}
		}
		printf("%d\n",ans);
		ans=0;
		memset(a,N,sizeof(a));
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
