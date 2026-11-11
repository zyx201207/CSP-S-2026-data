#include <iostream>
#include <stack>
using namespace std;

int n,m;
int a[101];
bool ca[101];
int va[101];
int na[101];
int ans[101];

int main(){
	cin >> n >> m;
	for (int i = 0;i < n;i++){
		cin >> a[i];
	}
	for (int i = 0;i < m;i++){
		ca[i] = false;
		ans[i] = 0;
	}
	for (int i = 0;i < n;i++){
		stack<int> c;
		for (int j = i+1;j < n;j++){
			if (ca[j]){
				for (int k = va[j];k <= c.size();k++){
					c.pop();
				}
			}
			else{
				c.push(a[j]);
				ca[a[j]] = true;
				va[a[j]] = j;
			}
		}
		bool f = false;
		for (int i = 0;i < c.size();i++){
			if (c.top() == a[i]){
				ans[a[i]]++;
				break;
			}
		}
	}
	for (int i = 0;i <= m;i++){
		cout << ans[i] << endl;
	}
	return 0;
}
