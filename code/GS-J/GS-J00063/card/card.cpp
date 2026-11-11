#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n,m;
	cin >> n>> m;
	string a[500];
	int c1 = 0,c2 = 0,c3 = 0;
	for (int i = 1;i <= n;i++){
		cin >> a[i];
	}
	for (int  i = 0;i <= n;i++){
		if(a[i]==1){
			c1++;
		}
		else if(a[i]==2){
			c2++;
		}
		else{
			c3++;
		}
	}
	cout << c1<< " "<< c2<< " "<< c3<< " "
	
	return 0;
}
