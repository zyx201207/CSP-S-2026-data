#include<iostream>
#include<string>
#include<queue>
using namespace std;
queue <int> a[50];
int c[50];
int n,m;
int ans = -1;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		int x;
		cin >> x;
		int u = x;
		for(int j = 1;u != 0;j++){
			if(u % 2 == 1){
				a[j].push(x);
				// cout << x << ' ' << j << ' ';
			} 
			c[j] += u % 2;
			u /= 2;
		}
	}
	for(int i = 40;i > 0;i--){
		if(c[i] == m){
			
			int u = -1;
			while(!a[i].empty()){
				int x = a[i].front();
				a[i].pop();
				// cout << a[i].front() << ' ';
				if(u == -1) u = x;
				else u &= x;
			}
			if(ans != -1){
				ans = max(ans,u);
			}else{
				ans = u;
			}
			break;
		}else if(c[i] > m){
			// cout << "TODO" << endl;
			int u = -1;
			while(!a[i].empty()){
				// cout << a[i].size() << ' ';
				int x = a[i].front();
				a[i].pop();
				// cout << a[i].front() << ' ';
				if(u == -1) u = x;
				else{
					u &= x;
					
				}
				
			}
			ans = max(ans,u);
		}
	}
	cout << ans;
	return 0;
}
