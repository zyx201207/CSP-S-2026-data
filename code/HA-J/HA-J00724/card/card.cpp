#include<bits/stdc++.h>
using namespace std;
stack<int>st;
int m,n,a[500010],b[300010],c[300010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(b[a[j]])while(st.top()!=a[j]&&(!st.empty()))st.pop();
			else st.push(a[j]);
			b[a[j]]++;
		}
		while(!st.empty()){
			int xx=st.top();
			c[xx]++;
			st.pop();
		}
	}
	for(int i=1;i<=m;i++)cout<<c[i]<<' ';
	return 0;
}
