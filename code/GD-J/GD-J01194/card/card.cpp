#include<bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;
const ll N=2e6+10,M=5e3+10;
ll n,m,a[N],ans[N];
stack<ll>table;map<ll,ll>cnt;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			//cout<<cnt[a[j]]<<" ";
			if(cnt[a[j]]==0){
				table.push(a[j]);
				cnt[a[j]]++;
			}else{
				while(!table.empty()){
					cnt[table.top()]=0;
					if(table.top()==a[j]){
						table.pop();
						break;
					}
					table.pop();
				}
				table.push(a[j]);
				cnt[a[j]]++;
			}
		}
		//cout<<"\n";
		while(!table.empty()){
			//cout<<table.top()<<" ";
			ans[table.top()]++;
			table.pop();
		}
		//cout<<"\n\n";
		cnt.clear();
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
} 
