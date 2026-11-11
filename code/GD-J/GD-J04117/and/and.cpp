#include <iostream>
using namespace std;
int main(){
	
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int m,n,p,q;
	cin>>m>>n;
	cin>>p>>q;
	for(int i=1;i<=n;i++){
		if (i==n/2){
			cout<<(i%17)-3;	
		}
	}
	return 0;
}
