#include <bits/stdc++.h>
using namespace std;
int n,a;
char aaa;
int ans[200005][3];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i = 1;i<=n;i++){
		cin >> a >> aaa;
		ans[i][2] = a;
		ans[i][1] = (aaa - 'a') + 1;
	}
	int x = n;
	int s = 1;
	long long sum = 0;
	bool boolaaa = 1;
	while(boolaaa){
		if(ans[s][1] == ans[x][1]){
			if(ans[s][2] < ans[x][2]){
				ans[x][2] = ans[x][2] - ans[s][2];
				ans[s][2] = 0;
				s++;
			}
			else{
				ans[s][2] = ans[s][2] - ans[x][2];
				ans[x][2] = 0;
				x--;
			}
		}
		else{
			if(ans[s][2] < ans[x][2]){
				ans[x][2] = ans[x][2] - ans[s][2];
				sum += ans[s][2];
				ans[s][2] = 0;
				s++;
			}
			else{
				ans[s][2] = ans[s][2] - ans[x][2];
				sum += ans[x][2];
				ans[x][2] = 0;
				x--;
			}
		}
		if(s == x){
			cout << sum;
			return 0;
		}
	}
	return 0;
}
