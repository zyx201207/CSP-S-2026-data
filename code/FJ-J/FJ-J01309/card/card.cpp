#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
stack<int> sta;
int a[500001];
int b[300001];
int ans[300001];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(b[a[j]]==1){
				while(sta.top()!=a[j]){
					b[a[sta.top()]]--;
					sta.pop();
				}
				sta.pop();
				b[a[j]]--;
			}
			sta.push(a[j]);
			b[a[j]]++;
		}
		while(!sta.empty()){
			int q=sta.top();
			sta.pop();
			ans[q]++;
			b[q]=0;
		}
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
	return 0;
}
