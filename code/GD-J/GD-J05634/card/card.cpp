#include<bits/stdc++.h>
using namespace std;
int a[500010],b[300010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int c[300010];
		stack<int>st;
		for(int j=i;j<=n;j++){
			if(c[a[j]]==0){
				st.push(a[j]);
				c[a[j]]++;
			}else{
				while(st.top()!=a[j]){
					st.pop();
				}
			}
		}
		while(!st.empty()){
			b[st.top()]++;
			st.pop();
		}
	}
	b[a[n]]=n;
	for(int i=1;i<=m;i++){
		cout<<b[i]<<" ";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
