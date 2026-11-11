#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 2e5;
int a[N];
int n,m;
int maxx = -1;
void dfs(int x,int s,int k,int c){
	if (x > n){
		if (c == m) maxx = max(maxx,s);
		return;
	}
	dfs(x+1,k?s&a[x]:a[x],1,c+1);
	dfs(x+1,s,k,c);
	return;
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	int m1 = -1;
	int m2;
	for (int i = 1;i<=n;i++){
		cin >> a[i];
		m1 = max(m1,a[i]);
	}
	if (n <= 20){
		dfs(1,0,0,0);
		//dfs(2,)
		cout << maxx;
	}
	else if (n>20 && n <= 2000){
		if (m == 1){
			cout << m1 <<endl; 
		}
		else if (m == n){
			m2 = a[1];
			for (int i = 2;i<=n;i++){
				//cout << a[i] <<endl;
				m2 &= a[i];
			}
			cout << m2 <<endl;
		}
		else{
			for (int i = 1;i<n;i++){
				for(int j=i+1;j<=n;j++){
					maxx = max(a[i]&a[j],maxx);
				}
			}
			cout << maxx <<endl;
		}
	}
	else if (n > 2000){
		if (m == n-1){
			m2 = a[1];
			for (int i = 2;i<=n;i++){
				//cout << a[i] <<endl;
				m2 &= a[i];
			}
			for (int i = 1;i<=n;i++){
				maxx = max(m2 & a[i],maxx);
			}
			cout << maxx <<endl;
		}
	}
	return 0;
}
