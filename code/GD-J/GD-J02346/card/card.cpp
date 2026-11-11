#include<bits/stdc++.h>
using namespace std;

int n,m,x,a[500005],cnt[300005];
bool use[300005];
stack<int> sta;

int main(){
	
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	
	for(int i=1;i<=n;i++){
		if(use[a[i]]){
			while(sta.top()!=a[i]){
				cnt[sta.top()]-=i;
				use[sta.top()]=false;
				sta.pop();
			}
			sta.pop();
		}
		else{
			cnt[a[i]]+=i;
			use[a[i]]=true;
		}
		sta.push(a[i]);
	}
	
	for(int i=1;i<=m;i++){
		cout<<cnt[i]<<' ';
	}
	
	return 0;
}
