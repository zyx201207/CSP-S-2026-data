#include<bits/stdc++.h>
using namespace std;
stack<int> st;
int n,m;
int a[300005];
int b[300005];
int f[500005];
int y[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>f[i];
	}
	for(int i=1;i<=n;i++){
		int x=f[n-i+1];
		if(a[x]){
			while(st.top()!=x){
				int t=st.top();
				a[t]=0;
				y[t]+=(i-b[t]);
				b[t]=0;
				st.pop();
			}
		}
		else{
			a[x]++;
			st.push(x);
			b[x]=i;
		}
	}
	for(int i=1;i<=m;i++){
		if(y[i]&&b[i]){
			cout<<(y[i]+n-b[i])<<" ";
		}
		else if(y[i]){
			cout<<y[i]<<" ";
		}
		else if(b[i]){
			cout<<(n-b[i]+1)<<" ";
		}
		else{
			cout<<'0'<<" ";
		}
	}
	return 0;
} 

