#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,a[500005];
ll tong[500005];
bool b[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	ll n1=n;
	stack<int> st;
	while(n1--){
		memset(b,0,sizeof b);
		for(int i=n-n1;i<=n;i++){
			st.push(a[i]);
			if(b[a[i]]==true){
				st.pop();
				while(st.top()!=a[i] && st.size()>1){
					if(st.top()==a[i]){
						break;
					}
					st.pop();
				}
			}
			b[a[i]]=true;
		}
		for(int i=0;i<=st.size();i++){
			tong[st.top()]++;
			st.pop();
		}
	}
	for(int i=1;i<=m;i++){
		cout<<tong[i]<<' ';
	}
	return 0;
}
