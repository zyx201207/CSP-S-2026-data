#include<bits/stdc++.h>
#define ll long long
using namespace std;
int a[500005],ans[300005];
bool flag[300005];
stack<int> s;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int j=1;j<=n;j++){
		for(int i=j;i<=n;i++){
			if(flag[a[i]]){
				while(s.top()!=a[i]){
					flag[s.top()]=0;
					s.pop();
				}
			}
			else s.push(a[i]),flag[a[i]]=1;
		}
		for(int i=1;i<=m;i++){
			if(flag[i]) ans[i]++;
		}
		for(int i=1;i<=m;i++) if(flag[i]) flag[i]=0;
		while(!s.empty()) s.pop();
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
	return 0;
}
