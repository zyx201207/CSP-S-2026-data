#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int mark[300005];
int arr[500005];
int main(){
	freopen("card.in" , "r" , stdin);
	freopen("card.out" , "w" , stdout);
	ios :: sync_with_stdio(false);
	cin.tie(nullptr); 
	
	int n , m; cin >> n >> m;
	for(int i = 1;i <= n;i++) cin >> arr[i];
	
	for(int _ = 1;_ <= m;_++){
		int ans = 0;
		for(int i = 1;i <= n;i++){
			stack<int> st;
			memset(mark , 0 , sizeof(mark));
			for(int j = i;j <= n;j++){
				if(mark[arr[j]] != 0) {
					while(st.top() != arr[j]){
						mark[st.top()]--;
						st.pop();
					}
				} else {
					st.push(arr[j]);
					mark[arr[j]]++;
				}
			}
			ans += (mark[_] != 0);
		}
		cout << ans << " ";
	}
	cout << endl;
	
	return 0;
}
