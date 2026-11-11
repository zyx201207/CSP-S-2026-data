#include<bits/stdc++.h>
using namespace std;
int n,m,a[5010],ans[5010];
bool ins[5010];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		stack<int> s;
		memset(ins,0,sizeof(ins));
		for(int j=i;j<=n;j++){
			if(ins[a[j]]){
				while(!s.empty()&&s.top()!=a[j]){
					ins[s.top()]=0;
					s.pop();
				}
			}
			else{
				s.push(a[j]);
				ins[a[j]]=1;
			}
		}
		for(int j=1;j<=n;j++){
			if(ins[j]) ans[j]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
