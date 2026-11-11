#include<bits/stdc++.h> 
using namespace std;
int n,m;
int p[500005];
bool f[300005];
int ans[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>p[i];
	}
	for(int i=1;i<=n;i++){
		memset(f,0,sizeof(f));
		stack<int>a;
		for(int j=i;j<=n;j++){
			if(f[p[j]]==true){
				while(a.top()!=p[j]&&!a.empty()){
					a.pop();
				}
				a.pop();
			}
			a.push(p[j]);
			f[p[j]]=true;
		}
		while(!a.empty()){
			ans[a.top()]++;
			a.pop();
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
