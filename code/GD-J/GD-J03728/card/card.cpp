#include <bits/stdc++.h>
using namespace std;
int n,m,a[500005],ans[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		scanf("%d",&a[i]);
	}
	for(int i = 1;i <= n;i++){
		vector <int> t;
		int c[300005] = {};
		for(int j = i;j <= n;j++){
			if(!c[a[j]]){
				t.push_back(a[j]);
				c[a[j]]++;
			}
			else{
				while(t.back() != a[j]){
					c[t.back()]--;
					t.pop_back();
				}
			}
		}
		while(!t.empty()){
			ans[t.back()] ++;
			t.pop_back();
		}
	}
	for(int i = 1;i <= m;i++){
		printf("%d ",ans[i]);
	}
	return 0;
}
