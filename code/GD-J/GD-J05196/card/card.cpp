#include <bits/stdc++.h>
using namespace std;
int n, m;
const int maxn = 5*1e5+5;
int a[maxn];
int ans; 
void check(int i){
	int c[n-1+1];
	/**/for (int j=0;j<n;j++)
		c[j] = a[i+j];
	ans=0;
	stack<int> s;
	int l = n-i+1;
	/**/for (int i=0;i<l;i++){
		s.push(c[i]);
		/**/for (int j=i;j>=0;j--){
			if (c[j] == c[i]){
				/**/for (int k=j;k<i;k++) {
					c[k] = -1;
					s.pop();
				}
				s.pop();
			}
		}
	}int x;
	while (!s.empty()){
		if (s.top() == i) ans+=1;
		s.pop(); 
	}
	cout << ans << " ";
}
int main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	/**/for (int i=0;i<n;i++)
		cin >> a[i];
	/**/for (int i=0;i<n;i++){
		check(i);
	}
	
	
	return 0;
}
