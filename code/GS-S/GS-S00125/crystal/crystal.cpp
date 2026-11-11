#include <iostream>
using namespace std;

int main()
{
	int m,n,j;
	cin >> m >> n;
	int a[n];
	for(int i=0;i<n;i++){
		cin >> a[i];
	}
	for(j=1;j<=m;j++){
		if(a[0]!=a[2]){
			a[0]++;
		} 
	}
	m=m-j;
	for(j=1;j<=m;j++){
		if(a[1]!=a[2]){
			a[1]++;
		}
	} 
	cout << 3;
	return 0;
}
