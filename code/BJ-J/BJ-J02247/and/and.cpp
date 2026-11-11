#include<bits/stdc++.h>
using namespace std;

int n,m,sum = 0;
int a[200010],f[200050];
bool vis[200010];

void dps(int wei,int s){
	if(wei > m){
		if(s >= sum)sum = s;
		return ;
	}
	for(int i = 1;i <= n;i++){
		if(!vis[i]){
			vis[i] = 1;
			if(wei == 1)s = a[i];
			else s = s & a[i];
			return dps(wei+1,s);
			vis[i] = 0;
		}
	}
}

int main(){
	
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	
	
	cin >> n >> m;

	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	
	if(m == n){
		sum = a[1];
		for(int i = 2;i <= n;i++){
			sum = a[i] & sum;
		}
		cout << sum;
	}
	else if(m == 1){
		sum = 0;
		for(int i = 1;i <= n;i++){
			if(sum <= a[i]){
				sum = a[i];
			}
		}
		cout << sum;
	}
	
	else if(m == 2){
		sum = 0;
		for(int i = 1;i <= n;i++){
			for(int j = i+1;j <=n;j++){
				int cur = a[i] & a[j];
				if(cur >= sum)sum = cur;
			}
		}
		cout << sum;
	}
	
	else if(n <= 40){
		dps(1,0);
		cout << sum;
	}
	
	return 0;
	
}
