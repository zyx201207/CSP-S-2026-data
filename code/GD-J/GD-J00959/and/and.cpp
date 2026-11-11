include <bits/c++std.h> 
using namespace std;

int main(){
	freopen('and.in' , 'r' , in)
	freopen('and.out' , 'w' , out)
	int n , m , cnt = 0;
	cin >> n >> m;
	char a[n + 5];
	for (int i = 1;i <= n;i++){
		cin >> a[i];
	}
	for (int i = 1;i <= n;i++){
		for(int j = 1;j <= n;j++){
			if (a[i] & a[j] > cnt){
				cnt = a[i] & a[j];
			}
		}
	}
	cout << cnt;
	
	return 0;
}
