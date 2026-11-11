#include <iostream>
#include <string>
using namespace std;

long long n,m,a[201200],b[101020],c[10200];

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for (long long i=1;i<=n;i++){
		cin>>a[i];
	}
	while (n!=0){
		int i=0;
		b[i]+=a[i];
		c[b[i]]++; 
		
	}
	for (int i=1;i<=n;i++){
		cout<<b[i]<<" ";
	}
	return 0;
}
