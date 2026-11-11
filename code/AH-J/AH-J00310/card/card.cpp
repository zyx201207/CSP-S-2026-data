#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=5e5+10;
ll a[N],l[N],r[N],n,i,m,L=0,j,ans[N];
stack<ll> st;
int main(){
    freopen("card.in","r",stdin);
   freopen("card.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(i=1;i<=n;i++) cin>>a[i];
    if(m==1){
		cout<<n;
		exit(0);
	}
    for(i=1;i<=n;i++){
		memset(l,0,sizeof(l));
		for(j=i;j<=n;j++){
			if(l[a[j]]){
				while(st.top()!=a[j]){
					l[st.top()]=0;
					st.pop();
				}
			}
			else st.push(a[j]);
			l[a[j]]=j;
		}
		while(!st.empty()){
			ans[st.top()]++;
			st.pop();
		}
	}
	for(i=1;i<=m;i++) cout<<ans[i]<<" ";
	return 0;
}
