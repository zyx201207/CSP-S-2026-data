#include<bits/stdc++.h>
using namespace std;
int a[500005],b[3005][5005],c[300005],ans[300005];
bool f[300005];
stack<int>st;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	bool flag=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i-1]>a[i])flag=1;
	}
	if(!flag&&n>10000){
		for(int i=1;i<=n;i++){
			ans[a[i]]++;
		}
		for(int i=1;i<=m;i++){
			ans[i]+=ans[i-1];
			cout<<ans[i]<<' ';
		}
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(c[a[j]]==0)st.push(a[j]),c[a[j]]++;
			else{
				while(st.top()!=a[j]){
					c[st.top()]--;
					st.pop();
				}
				st.pop();
				st.push(a[j]);
			}
		}
		while(st.size()!=0){
			if(!f[st.top()]){
				ans[st.top()]++;
				f[st.top()]=1;
			}
			st.pop();
		}
		memset(f,0,sizeof(f));
		memset(c,0,sizeof(c));
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<' ';
	return 0;
}
