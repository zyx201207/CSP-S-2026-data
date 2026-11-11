#include <bits/stdc++.h>
using namespace std;
int a[500050];
int q[500050];
bool w[500050];
int n,m;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin>>n>>m;
	bool b = true;
	for(long long i = 1;i <= n;i++){
		cin>>a[i];
		if(i >= 2 and a[i - 1] > a[i]){
			b = false;
		}
	}
	if(n == 1){
		if(m == 1 and a[1] != 1){
			cout<<0;
		}
		else if(m == 1 and a[1] == 1){
			cout<<1;
		}
		else if(m == 2 and a[1] != 1){
			cout<<0<<" "<<0;
		}
		else if(m == 2 and a[1] == 1){
			cout<<1<<" "<<0;
		}
	}
	if(n == 2){
		if(a[1] == 1 or a[2] == 1){
			cout<<1;
		}
		if(m == 2 and a[1] == 2 or a[2] == 2){
			cout<<" "<<1;
		}
		else if(m == 2 and a[1] != 2 and a[2] != 2){
			cout<<" "<<0;
		}
		if(a[1] != 1 and a[2] != 1){
			cout<<0;
		}
	}
	long long num = 0;
	for(int i = 1;i <= n;i++){
		num++;
		q[i] = a[i];
		for(int j = 1;j <= num;j++){
			if(a[i] == q[j] and w[j] == true){
				num -= j;
				for(int k = j;k <= i;k++){
					w[k] = false;
				}
			}
		}
	}
	return 0;
}
