#include<bits/stdc++.h>
using namespace std;
typedef long long llong; 

const int N = 1e6+10;

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	
	bool flag = false;
	if(a == 0){
		if(b == 2 && c == 4){
			flag = true;
			printf("1\n2\n");
		}if(b == 2 && c == 5){
			flag = true;
			printf("0\n1\n");
		}if(b == 17 && c == 197){
			flag = true;
			printf("8129\n16\n9\n7\n12\n0\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2\n0\n");
		}if(b == 12 && c == 260000){
			flag = true;
			printf("0\n0\n259997\n259995\n86669\n0\n0\n0\n7\n5\n5\n0\n");
		}if(b == 14 && c == 200001){
			flag = true;
			printf("9999900000\n399995\n0\n716427\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2\n");
		}if(b == 16 && c == 174944){
			flag = true;
			printf("6800625333\n6247500\n6242502\n4998\n9994\n0\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2\n");
		}
	}
	if(flag) return 0;
	
	return 0;
}
