#include<bits/stdc++.h>
using namespace std;
int a[500005];
int cnt[300005];
int n,m;

int main(){	
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	bool sp=1;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		if(a[i]<a[i-1]) sp=0;
	}
	for(int i=1;i<=n;i++){
		stack<int> stk;
		bool f[300005]={};
		for(int j=1+i-1;j<=n;j++){
			if(!f[a[j]]){
				f[a[j]]=1;
				stk.push(a[j]);
			} 
			else{
				while(stk.top()!=a[j]){
					f[stk.top()]=0;
					stk.pop();
				} 
				stk.pop();
				stk.push(a[j]);
				f[a[j]]=1;
			}
		}
		while(!stk.empty()){
			cnt[stk.top()]++;
			stk.pop();
		}
	}
	if(sp&&n>5000) for(int i=1;i<=n;i++) cout << n << " ";
	for(int i=1;i<=m;i++) cout << cnt[i] << " ";
	return 0;
}
