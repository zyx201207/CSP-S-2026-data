#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 5;
ll n,m,a[N],x[N],ans;
bool b[N];

void dfs(int t)
{ 
	for (int i = 1;i <= n;i++){
		if (b[i] == 0){
			x[t] = i;
			b[i] = 1;
			if (t == m){
				ll sum = a[x[1]];
			 	for (int j = 2;j <= t;j++){
			 		sum = sum & a[x[j]];
				}
				ans = max(ans,sum);
			}
			dfs(t+1);
			b[i] = 0;
		}
	}	
}

int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >>n>>m;
	for (int i = 1;i <= n;i++){
		cin >>a[i];
	}
	if (n > 20){
		if (m == 1){
			for (int i = 1;i <= n;i++){
				ans = max(ans,a[i]);
			}
		}
		else if(m == n){
			ll s = a[1];
			for (int i = 2;i <= n;i++){
				s = s & a[i];
			}
			ans = s;
		}
		else if (m == 2){
		 	for(int i = 1;i <= n;i++){
		 		for (int j = i+1;j <= n;j++){
		 			ans = max(ans,a[i] & a[j]);
				 }
			 } 
		}
	}
	else{
		dfs(1); 
	}
	cout <<ans;
	return 0;
}


