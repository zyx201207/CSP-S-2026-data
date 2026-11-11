#include <bits/stdc++.h>
using namespace std;
int n,m;
const int N1=500005;
vector<int> vis(N1);
vector<int> a(N1);
void start(int u){
	int tvis[N1]={0};
	vector<int> mp(N1);
	int top=0;
	for(int i=u;i<=n;i++){
		if(tvis[a[i]]==0){
			tvis[a[i]]=++top;
			mp[top]=a[i];
		}
		else{
			for(int j=tvis[a[i]];j<=top;j++){
				if(tvis[mp[j]]>tvis[a[i]]) tvis[mp[j]]=0;
			}
			top=tvis[a[i]];
		}
	}
	memset(tvis,0,sizeof(tvis));
	for(int i=1;i<=top;i++){
		if(tvis[mp[i]]!=1){
			vis[mp[i]]++;
			tvis[mp[i]]=1;
		}
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		start(i);
	}
	for(int i=1;i<=m;i++){
		cout<<vis[i]<<' ';
	}
	
	
	return 0;
}
