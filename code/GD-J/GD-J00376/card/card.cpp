#include <bits/stdc++.h>
using namespace std;
stack<int> s;
int a[10001];
bool b[500005];
int ans[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	cin>>a[i];
	for(int j=1;j<=n;j++){
		for(int i=j;i<=n;i++){
			if(b[a[i]]==0){
				s.push(a[i]);
				b[a[i]]=1;
			}
			else
			{
				while(s.top()!=a[i]){
					b[s.top()]=0;
					s.pop();
				}
			}
		}
		while(!s.empty()){
			ans[s.top()]++;
			s.pop();
		}
		for(int k=j;k<=n;k++){
			b[a[k]]=0;
		}
	}
	for(int t=1;t<=m;t++){
		cout<<ans[t]<<" ";
	}
	return 0;
}
