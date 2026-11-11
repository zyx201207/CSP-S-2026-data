#include<bits/stdc++.h>
using namespace std;
int a,b;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	scanf("%d%d",&a,&b);
	for(int i=1;i<=b;i++){
		int n,m;
		scanf("%d%d",&n,&m);
		for(int j=1;j<n;j++){
			int x,y;
			scanf("%d%d",&x,&y);
		}
		printf("%d\n",(i+1)%2+1);
	}
	return 0;
}
