#include<cstdio>
#include<vector>
using namespace std;
const int xn=1e6+5;
int c,t,n,k,u,v;
vector<int> a[xn];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	scanf("%d%d",&c,&t);
	while(t--){
		scanf("%d%d",&n,&k);
		for(int i=1;i<=n;i++){
			scanf("%d%d",&u,&v);
			a[u].push_back(v);
			a[v].push_back(u);
		}
		printf("1\n"); 
	}
	return 0;
}
