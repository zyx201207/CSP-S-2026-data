#include<bits/stdc++.h>
using namespace std;
int a[200010],t[200010],te[200010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin >> n >> m;
	for(int i=1;i<=n;i++)cin >> a[i];
	for(int i=1;i<=n;i++){
		stack<int>s;
		memset(t,0,sizeof t);
		for(int j=i;j<=n;j++){
			if(t[a[j]]){
				while(s.top()!=a[j])s.pop();
			}else s.push(a[j]);
			t[a[j]]=1;
		}
		while(!s.empty()){
			te[s.top()]++;
			s.pop();
		}
	}
	for(int i=1;i<=m;i++)cout << te[i] << ' ';
	return 0;
}
