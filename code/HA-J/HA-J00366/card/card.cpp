#include<iostream>
#include<cstdio>
#include<queue>
#include<cmath>
using namespace std;
int n,m,a[500010],ans[300010];
queue<int> q,z;
bool bj[300010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(bj[a[i]]==true){
				bool pd=false;
				while(!q.empty()){
					int topp=q.front();
					if(topp==a[j]) pd=true;
					if(!pd){
						z.push(topp);
					}
					bj[topp]=false;
					q.pop();
				}
				while(!z.empty()){
					int topp=z.front();
					bj[topp]=true;
					q.push(topp);
					z.pop();
				}
				q.push(a[j]);
				bj[a[j]]=true;
			}
			else{
				q.push(a[j]);
				bj[a[j]]=true;
			}
		}
		while(!q.empty()){
			ans[q.front()]++;
			q.pop();
		}
	}
	for(int i=1;i<=m;i++){
		printf("%d ",ans[i]);
	}
	return 0;
}
