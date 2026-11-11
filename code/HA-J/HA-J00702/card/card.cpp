#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
/*4 3
1 2 1 3
*/
stack<ll> st;
ll a[500009],b[300009],ans[500009],nn;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ll n,m;
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	for(ll i=1;i<=n;i++){
		for(ll j=i;j<=n;j++){
			b[a[j]]++;
			if(b[a[j]]>1){
				while(st.top()!=a[j]){
					b[st.top()]--;
					st.pop();
				}
				b[st.top()]--;
				//cout<<st.top()<<" ";
				st.pop();
			}
			st.push(a[j]);
		}
		/*if(b[2]==1){
			cout<<"("<<i<<")";
		}*/
		for(ll k=1;k<=m;k++){
			/*if(b[2]==1){
				cout<<"("<<i<<")";
			}*/
			if(b[k]==1){
				ans[k]++;
				b[k]=0;
			}
		}
		while(!st.empty()){
			st.pop();
		}
	}
	for(ll i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
