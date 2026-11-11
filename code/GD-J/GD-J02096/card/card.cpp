#include<bits/stdc++.h>
using namespace std;
int n,m;
vector<int> a;
int f[300007];
int vis[300007];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++){
		int sum;
		scanf("%d",&sum);
		if(!vis[sum]){
			vis[sum]=i;
			a.push_back(sum);
		}
		else{
			for(int j=vis[sum];j<=a.size()-1;j++){
				a.pop_back();
				vis[j]=0;
			}
		}
		for(int j=1;j<=m;j++){
			if(vis[j]!=0) f[j]++;
		}
	}
	for(int i=0;i<n;i++){
		printf("%d ",f[i]);
	}
	return 0;
}
