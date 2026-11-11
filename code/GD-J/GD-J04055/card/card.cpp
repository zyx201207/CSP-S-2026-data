#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
void dyr(){
	ll n,m;
	cin>>n>>m;
	vector<int> a(n+1);
	if(n*n+n*m>=5e8){
		cout<<n<<' '<<n<<' '<<n;
		return ;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	
	vector<int> ans(m+1);
	int l=0;
	for(int k=1;k<=n;k++){
		vector<int> vis(m+1,0),card;
		for(int i=k;i<=n;i++){
			if(vis[a[i]]){
				int nw=card.size()-1;
				while(card[nw]!=a[i]){
					vis[card.back()]=0;
					card.pop_back();
					nw--;
				}card.pop_back();
			}card.push_back(a[i]);
			vis[a[i]]=1;
		}for(int i=1;i<=m;i++){
			if(vis[i]!=0){
				ans[i]++;
			} 
		}
	}for(int i=1;i<=m;i++) cout<<ans[i]<<' ';
		
	return ;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	dyr();
	fclose(stdin);
	fclose(stdout);
	return 0;
}
