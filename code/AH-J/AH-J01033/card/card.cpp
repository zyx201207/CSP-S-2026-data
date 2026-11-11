#include<bits/stdc++.h>
using namespace std;
int a[500005];
bool t[300005];
int ans[300005];
int main(){
	//ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin >> n >> m;
	for(int i = 1;i <= n;i ++){
		cin >> a[i];
	}
	for(int i = 1;i <= n;i ++){
		//memset(t,sizeof(t),0);
		//stack<int> st;
		for(int j = i;j <= n;j ++){
			if(!t[a[j]]){
				t[a[j]] = 1;
				//st.push(a[j]);
				//ans[a[j]] ++;
			}else{
				//t[a[j]] = 0;
				for(int k = j - 1;k >= 1;k --){
					if(a[k] == a[j])break;
					else {
						//st.pop();
						t[a[k]] = 0;
						//ans[a[k]] --;
					}
				}
			}
		}
		for(int j = 1;j <= m;j ++){
			if(t[j] == 1) ans[j] ++;
			t[j] = 0;
		}
		//while(!st.empty()){
		//	t[st.top()] = 0;
		//	st.pop();
		//}
		//cout << endl;
	}
	for(int i = 1;i <= m;i ++)cout << ans[i] << ' ';
	return 0;
}

