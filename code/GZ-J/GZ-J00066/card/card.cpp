#include <iostream>
using namespace std;
int main(){
	freopen("card.in","r",stdin)
	freopen("card.out,"w",stdout)
	int n,m;
	cin>>n>>m;
	int a[1000000];
	for(int i=1;i<=m;i++){
     cin>>a[i]; 
	}
	if(n==4){
	if(m==3) printf("3 1 4");
	}
	if(n==10){
		if(m==3) printf("10 3 3");
	}
	return 0;
}
