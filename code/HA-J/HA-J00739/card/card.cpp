#include<bits/stdc++.h>
using namespace std;
stack <int> stk;
int cnt[300005],n,m,a[500005],ans,mk[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	while(ans <= m){
		ans++;
		
		for(int i = ans;i <= n;i++){
			int flag = 0;
			for(int j = 1;j <= i;j++){
				if(a[i] == a[j]){
					flag = 1;
					break;
				}
			}
			if(flag){
				for(;stk.top() != a[i];){
					stk.pop();
				}
			}
			else{
				stk.push(a[i]);
				
			}
		}
		while(stk.size()){
			cnt[stk.top()]++;
			stk.pop();
		}
	}
	for(int i = 1;i <= m;i++){
		cout << cnt[i];
	}
	return 0;
}