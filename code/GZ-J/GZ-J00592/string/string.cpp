//GZ-J00592
//遵义市新蒲新区滨湖中学
//邓佳琪 
#include <bits/stdc++.h>
using namespace std;
int N = 200005;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n, x[N], sum = 0;
	char c[N];

	
	cin >> n;
	for (int i = 1;i <= n;i ++){
		cin >> x[i] >> c[i];
		sum += x[i]; 
	}
	
	long long m = sum / 2;
	//cout << m << endl;
	
	long long a = 1, b = n, ans = 0;
	while(m > 0){
		if (a == b) break;
		if (c[a] != c[b]){
			if (x[a] >= x[b]){
				x[a] -= x[b];
				ans += x[b];
				m -= x[b];
				b -= 1;
				if(x[a] == 0) a += 1;
				//cout << a << " " << b << " " << ans << " " << m << endl; 
			}
			else{//x[a] < x[b]
				x[b] -= x[a];
				ans += x[a];
				m -= x[a];
				a += 1;
				//cout << a << " " << b << " " << ans << " " << m << endl; 
			}
		}else{
			if (c[a] == c[b]){
			if (x[a] >= x[b]){
				x[a] -= x[b];
				m -= x[b];
				b -= 1;
				if (x[a] == 0) a += 1;
			}
			else{
				x[b] -= x[a];
				m -= x[a];
				a += 1;
				}
			}
		}
		
		
	}
	
	cout << ans;
	
	return 0;
}
