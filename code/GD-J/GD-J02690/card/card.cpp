#include <iostream>
using namespace std;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n;
	int m;
	int a[100];
	int cn[100];
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	for(int i=n;i>=1;i--){
		cout<< a[i]-1;
	}
	return 0;
 } 
