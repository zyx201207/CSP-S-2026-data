include <bits/c++std.h> 
using namespace std;

int main(){
	freopen('string.in' , 'r' , in)
	freopen('string.out' , 'w' , out)
	int n , cnt = 0 , num = 0;
	cin >> n;
	char a[2][n];
	for (int i = 1;i <= 2;i++){
		for (int j = 1;j <= n;j++){
			cin >> a[i][j];
		}
	}
	for (int i = 2;i <= 2;i++){
		for (int j = 1;j <= n;j++){
			if (a[i][j] == a[i][j + 1]){
				cnt++;
			}
		}
	}
	for (int i = 1;i <= 1;i++){
		for (int j = 1;j <= n;j++){
			num += a[i][j];
		}
	}
	if (cnt == n - 1){
		cout << '0';
	}
	else {
		cout << num / 2;
	}
	
	
	return 0;
}
