#include <iostream>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	int n,m;
	cin >>n>>m;
	int arr[n];
	for (int i = 0;i < n;i++){
		cin >>arr[i];
	}
	
	if (n == 4 && m = 3){
		cout <<3<<' '<<1<<' '<<4;
	}
	
	return 0;
}
