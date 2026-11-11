#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a[500010],ans[500010],t[500010];
stack <ll>q;
int main(){
	
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		memset(t, 0, sizeof t);
		for(int j=i;j<=n;j++){
			q.push(a[j]);
			t[a[j]]++;
			if(t[a[j]]==2){
				t[a[j]]--;
				q.pop();
				while(q.top()!=a[j]){
					t[q.top()]--;
					q.pop();
				}
				
			}
		}
		while(!q.empty()){
			ans[q.top()]++;
			q.pop();
		}
	}
	for(int i=1;i<=m;i++)
		cout<<ans[i]<<' ';
	
	return 0;
}
