#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
int x[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	scanf("%d%d",&c,&t);
	
	if(c==11||c==12){
		while(t--){
			int n,d;
			scanf("%d%d",&n,&d);
			for(int i=1;i<=n;i++){
				scanf("%d",&x[i]);
			}
			
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
