#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005];
int num[300005];
vector<int> v[300005];
void tree(int x){
	//printf("%d",x);
	for(int i=0;i<(int)v[x].size();i++){
		tree(v[x][i]);
		num[x]+=num[v[x][i]];
	}
	return;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=n;i>=1;i--){
		if(num[a[i]]==0){
			v[a[i+1]].push_back(a[i]);
		}
		num[a[i]]++;
	}
	tree(0);
	for(int i=1;i<=m;i++){
		printf("%d ",num[i]);
	}
	return 0;
}
