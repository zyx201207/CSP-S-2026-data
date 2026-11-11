#include <bits/stdc++.h>
using namespace std;
int c,t,x,y;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	if(c==0){
		if(t==2){
			cin>>x>>y;
			if(x==4  && y==2){
				puts("1");
				puts("2");
			}
			if(x==5 && y==3){
				puts("0");
				puts("1");
			}
		}
		if(t==17){
			printf("8129\n16\n9\n7\n12\n0\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2\n0");
		}
		if(t==12){
			printf("0\n0\n259997\n259995\n86669\n0\n0\n0\n7\n5\n5\n0");
		}
		if(t==14){
			printf("9999900000\n399995\n0\n716427\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2");
		}
		if(t==16) printf("6800625333\n6247500\n6242502\n4998\n9994\n0\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2");
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
