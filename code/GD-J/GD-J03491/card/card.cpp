#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=3e5+10;
ll n,m,ar[N],lst[N],ans[N],k;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>ar[i];
	}
	stack<int> st;
	for(ll i=1;i<=n;i++){
		for(ll j=i;j<=n;j++){
			if(lst[ar[j]]==0){
				st.push(ar[j]);
				k++;
				lst[ar[j]]=k;
			}
			else{
				ll tem=k-lst[ar[j]]+1;
				for(ll a=1;a<=tem;a++){
					lst[st.top()]=0;
					st.pop();
				}
				st.push(ar[j]);
				k=k-tem+1;
				lst[ar[j]]=k;
			}
		}
		while(!st.empty()){
			ans[st.top()]++;
			st.pop();
		}
		k=0;
		memset(lst,0,sizeof(lst));
	}
	for(ll i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
	
	return 0;
}
