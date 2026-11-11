#include <iostream>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n ,m,a[520];
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		cin>>a[i];
	}

	cout<<a[n]<<" "<<a[5];
	return 0;
}
