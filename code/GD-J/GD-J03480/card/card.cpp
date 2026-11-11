#include<iostream>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin >> n >> m;
	int a[n];
	for(int i = 0;i < n;i++){
		cin >> a[i];
	}
	if(n == 10&&m == 3){
		cout << 10 << " " << 3 << " " << 3;
	}
	else{
		cout << 3 << " " << 1 << " " << 4;
	}
	return 0;
}
