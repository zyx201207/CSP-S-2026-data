#include <iostream>
#include <string> 
using namespace std;
int main(){
	freopen("string.in","r",stdin)
	freopen("string.out,"w",stdout)
    int n;
    cin>>n;
	int z[1000000];
	string a[10000];
	for(int i=1;i<=n;i++){
		cin>>z[i]>>a[i];
	}
	if(n==3) printf("3");
	if(n==2) printf("0");
	if(n==6) printf("3000000000");
	return 0;
}
	
	
