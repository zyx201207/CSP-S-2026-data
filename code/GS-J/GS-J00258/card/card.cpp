#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	for(int i=0;i<=100;++i){
		for(int j=100;j>=1;--j){
			printf("%d%d%d",i,j,i+j);
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
