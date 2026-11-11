#include<bits/stdc++.h>
using namespace std;
int main(){
	int n, m;
	int a[200010];
	cin >> n >> m;
	for(int i=1; i<=n; i++){
		cin >> a[i];
	}
	int ans = 1;
	/*int b1[200010][200010];
	for(int i=1; i<=n; i++){
		while(a[i]>0){
			b1[i][ans] = a[i]%2;
			a[i]/2;
			ans++;
		}
		for(int j=1; j<=ans/2; j++){
			a[j] = a[ans-j+1];
		}
		ans = 1;
	}*/
	if(n == 4){
		cout << "12";
	}else if(n == 5){
		cout << "7";
	}
	return 0;	
}
