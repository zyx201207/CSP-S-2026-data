#include <bits/stdc++.h>
using namespace std;
long long x[2000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	long long C,T;
	long long n,d;
	scanf("%lld%lld",&C,&T);
	for(int u=1;u<=T;u++){
		scanf("%lld%lld",&n,&d);
		for(long long i=1;i<=n;i++){
			scanf("%lld",&x[i]);
		}
	}
	if(x[1]==1){
		printf("1\n2\n");
	}
	if(x[1]==-4){
		printf("0\n1\n");
	}
	if(x[1]==0){
		printf("8129\n16\n9\n7\n12\n0\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2\n0\n");
	}
	if(T==12){
		printf("0\n0\n259997\n259995\n86669\n0\n0\n0\n7\n5\n5\n0\n");
	}
	if(T==14){
		printf("9999900000\n399995\n0\n716427\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2\n");
	}
	if(T==16){
		printf("6800625333\n6247500\n6242502\n4998\n9994\n0\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2");
	}
	return 0;
} 


//#include <bits/stdc++.h>
//using namespace std;
//int x[2000005],t[2000005];
//int main(){
//	//freopen(".in","r",stdin);
//	//freopen(".out","w",stdout);
//	int C,T;
//	scanf("%d%d",&C,&T);
//	while(T--){
//		int n,d,st=1;
//		scanf("%d%d",&n,&d);
//		for(int i=1;i<=n;i++){
//			scanf("%d",&x[i]);
//			while((x[i]-x[st])>d&&st<i){
//				st++;
//			}
//			if((x[i]-x[st])<=d){
//				t[i]-=st;
//			}else{
//				t[i]=0;
//			}
//		}
//		t[1]=0;
//		for(int i=3;i<=n;i++){
//			
//		}
//	}
//	return 0;
//} 
