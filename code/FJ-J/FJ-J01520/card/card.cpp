#include <bits/stdc++.h>
using namespace std;
const int N=5e5,M=3e5;
int a[N+5];
int n,m;
long long ans[M+5];
bool vis[M+5];
stack<int> s;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		cout<<(n+1)/2;
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			vis[j]=0;
		}
		while(!s.empty()){
			s.pop();
		}
		for(int j=i;j<=n;j++){
			if(vis[a[j]]==0){
				vis[a[j]]=1;
				s.push(a[j]);
				ans[a[j]]++;
			}
			else{
				while(!s.empty()&&s.top()!=a[j]){
					ans[s.top()]--;
					vis[s.top()]=0;
					s.pop();
				}
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
	return 0;
}
