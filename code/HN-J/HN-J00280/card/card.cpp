#include<bits/stdc++.h>
using namespace std;
const int N = 5e5, M = 3e5;
int n, m, len;
int last[M], st[N], a[N], ans[M];
void pop(){
	if(len>0) len--;
}
int main(){
	ios::sync_with_stdio();
	cin.tie(0);
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin>>n>>m;
	for(int i = 1;i <= n;i++){
		cin>>a[i]; 
	} 
	for(int i = 1;i <= n;i++){
		memset(last, -1, sizeof(last));
		len = 0;
		for(int j = i;j <= n;j++){
			if(last[a[j]]>0){
				while(len && st[len]!=a[j]){
					last[st[len]] = -1;
					pop();
				}
				pop();
			}
			st[++len] = a[j];
			last[a[j]] = 1;
		}
		for(int i = 1;i <= len;i++){
			ans[st[i]]++;
		}
	}
	for(int i = 1;i <= m;i++){
		cout<<ans[i]<<' ';
	}
	cout<<'\n';
	fclose(stdin);
	fclose(stdout);
	return 0;
}
