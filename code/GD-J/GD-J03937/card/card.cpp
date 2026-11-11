#include <bits/stdc++.h> 
using namespace std;
int n,m; 

int main(){
	
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int a[100];
	cin >> n >> m;
	for(int i = 1;i<= n;i++){
		cin >> a[i];
		
	}
	cout << n<<" "<<a[1]<<" "<<m;
	return 0;
}
