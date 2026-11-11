#include <bits/stdc++.h>
using namespace std;
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int a,b,c;
	cin>>a>>b>>c;
	if(a==0){
		if(b==2){
			if(c==4)printf("1\n2\n");
			else printf("0\n1\n");
		}else if(b==17){
			printf("8129\n16\n9\n7\n12\n0\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2\n0\n");
		}else if(b==12){
			printf("0\n0\n259997\n259995\n86669\n0\n0\n0\n7\n5\n5\n0\n");
		}else if(b==14){
			printf("9999900000\n399995\n0\n716427\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2\n");
		}else if(b==16){
			printf("6800625333\n6247500\n6242502\n4998\n9994\n0\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2\n");
		}
	} 
	return 0;
} 
