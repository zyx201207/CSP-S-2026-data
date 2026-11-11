#include<bits/stdc++.h>
using namespace std;
int n,m,a[500010],q[500010],t,vis[500010],ans[500010],ok1=1;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i>1&&a[i-1]>a[i]){
			ok1=0;
		}
	}
	if(ok1){
		for(int i=1;i<=n;i++){
			if(i==n||a[i+1]!=a[i]){
				ans[a[i]]=i;
			}
		}
		for(int i=1;i<=m;i++){
			cout<<ans[i]<<' ';
		} 
		cout<<endl;
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(!vis[a[j]]){
				vis[a[j]]=1;
				q[++t]=a[j];
			}else{
				while(q[t]!=a[j]){
					vis[q[t]]=0;
					t--;
				}
			}
		}
		while(t){
			ans[q[t]]++;
			vis[q[t]]=0;
			t--;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
	cout<<endl;
	return 0;
}
