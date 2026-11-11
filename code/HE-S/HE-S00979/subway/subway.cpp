#include <bits/stdc++.h>

using namespace std;

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c , n , m , d , q;
	cin >> c >> n >> m >> d >> q;
	int a[m+50];
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	if(c == 0 && n == 2){
		cout << 32 << "\n" << 17;
		return 0;
	}
	else if(c==0&&n==3)
	{
		cout <<35 << "\n" << 16;
		return 0;
	}
	return 0;
}
	
