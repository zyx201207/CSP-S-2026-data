#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
const int N = 200005;
int a[N];
int ans = -1;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);	cin.tie(0);	cout.tie(0);
	int n,m;
	cin>>n>>m;
	int maxn = -1;
	for(int i = 1; i <= n; i++){
		cin>>a[i];
		maxn = max(maxn, a[i]);
	}
	if(n <= 20){
		for(int i = 1; i <= (1<<n)-1; i++){
			int cnt = 0;
			int cnt_1 = 1;
			int num = i;
			int op = -1;
			while(num){
				if(num&1){
					if(op == -1){
						op = a[cnt_1];
					}
					else{
						op = op&a[cnt_1];
					}
					cnt++;
				}
				cnt_1++;
				num>>=1;
			}
			if(cnt==m){
				ans = max(ans, op);
			}
		}
		cout<<ans;
	}
	else if(n <= 200000){
		if(m == 1){
			cout<<maxn;
		}
		else if(m == n){
			int k;
			for(int i = 1; i <= n; i++){
				if(i == 1){
					k = a[i];
				}
				else{
					k = k&a[i];
				}
			}
			cout<<k;
		}
		else if(m == 2){
			for(int i = 1; i <= n; i++){
				for(int j = i+1; j <= n; j++){
					ans = max(ans, a[i]&a[j]);
				}
			}
			cout<<ans;
		}
	}
	else if(maxn < 4){
		int num0 = 0,num1 = 0,num2 = 0,num3 = 0;
		for(int i = 1; i <= n; i++){
			if(a[i] == 0){
				num0++;
			}
			else if(a[i] == 1){
				num1++;
			}
			else if(a[i] == 2){
				num2++;
			}
			else if(a[i] == 3){
				num3++;
			}
		}
		int mm = m;
		mm = mm-num1-num3;
		if(mm <= 0){
			cout<<3;
		}
		else{
			mm -= num2;
			if(mm <= 0){
				cout<<2;
			}
			else{
				cout<<0;
			}
		}
	}
	else{
		cout<<maxn;
	}
	return 0;
}
