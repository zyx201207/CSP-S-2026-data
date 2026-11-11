//侯欣言  GZ-J00428 兴义市弘毅中学
#include <bits/stdc++.h>
using namespace std;
long long m,n;
long long card[1000000];
long long ge[1000000];
struct panduan{
	long long wei;
	bool shi;
};
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%lld %lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&card[i]);
	}
	
	for(int i=1;i<=n;i++){
		panduan pan[100000];
		for(int y=i;y<=n;y++){
			if(pan[card[y]].shi==false){
				pan[card[y]].shi=true;
				pan[card[y]].wei=y;
			}else if(pan[card[y]].shi!=false){
				for(int x=pan[card[y]].wei;x<y;x++){
					pan[card[x]].shi=false;
					pan[card[x]].wei=0;
				}
				pan[card[y]].shi=true;
				
			}
		}
		for(int o=1;o<=n;o++){
			if(pan[o].shi==true){
				//printf("%d ",i);
				ge[o]++;
				pan[o].shi=false;
				pan[o].wei=0;
			}
		}
	}
	for(int i=1;i<=m;i++){
		printf("%lld ",ge[i]);
	}
	return 0;
}
/*10 3
3 1 2 1 3 2 3 1 2 1*/
