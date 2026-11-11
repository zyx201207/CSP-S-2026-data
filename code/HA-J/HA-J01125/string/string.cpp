#include <bits/stdc++.h>
using namespace std;
struct word{
	long long num;
	char c;
}a[1000010];
int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n;
	long long cnt = 0;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i].num >> a[i].c;
	int x = 1, y = n;
	while (x < y){
		if (a[x].c != a[y].c){
			if (a[x].num > a[y].num){
				cnt+=a[y].num;
				a[x].num -= a[y].num;
				a[y].num = 0;
				y--;
			}else{
				cnt+= a[x].num;
				a[y].num-=a[x].num;
				a[x].num = 0;
				x++;
			}
		}else{
			if (a[x].num > a[y].num){
				a[x].num -= a[y].num;
				a[y].num = 0;
				y--;
			}else{
				a[y].num-=a[x].num;
				a[x].num = 0;
				x++;
			}
		}
	}
	cout << cnt; 
	fclose(stdin);
	fclose(stdout);
	return 0;
}
