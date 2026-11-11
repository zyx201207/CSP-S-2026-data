#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int a[500010];
int ans[300010];
bool b[300010];
int idx[300010];
int p[500010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=0;i<n;i++){
		int id=0;
		memset(b,0,sizeof b);
		for(int j=i;j<n;j++){
			if(!b[a[j]]){
				p[id]=a[j];
				b[a[j]]=1;
				idx[a[j]]=id;
			}else{
				id=idx[a[j]];
			}
			id++;
		}
		for(int j=0;j<id;j++){
			ans[p[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		printf("%d ",ans[i]);
	}
	return 0;
}
