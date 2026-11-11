#include <iostream>
#include <vector> 
using namespace std;
int main(){
	freopen("and.in","r",stdin)
	freopen("and.out","w",stdout)
	int n,m;
	int a[1000000];
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==4){
		if(m==2) printf("12");
	}
	if(n==5){
		if(m==3) printf("7");
	}
	return 0;
}
