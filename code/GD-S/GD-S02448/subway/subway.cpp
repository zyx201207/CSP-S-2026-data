#include <bits/stdc++.h>//dij
using namespace std;
const int N=500005;
struct node{
	vector<int> v;
	vector<int> vn;
	int minn;
}s[N];
int c,n,m,d,q,a[N],k,point,num;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&k);
		for(int j=1;j<=k;j++){
			scanf("%d%d",&point,&num);
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
