#include <bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500024],ans[300024];
bool f[500024];
stack <long long> stk;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	for(int i = 1;i <= n;i++){
		memset(f,0,sizeof(f));
		for(int j = i;j <= n;j++){
			if(f[a[j]]==1){
				while(stk.top()!=a[j]&&!stk.empty()){
					stk.pop();
				}
				f[a[j]]=0;
			}else{
				stk.push(a[j]);
				f[a[j]]=1;
			}
		}
		while(!stk.empty()){
			ans[stk.top()]++;
			stk.pop();
		}
	}
	for(int i = 1;i <= m;i++){
		cout << ans[i] << ' ';
	}
	return 0;
}
