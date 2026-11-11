#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],t[300005];
bool f[300005];
stack<int> q;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++) f[j]=0;
		for(int j=i;j<=n;j++){
			if(f[a[j]]==1){
				while(q.top()!=a[j]) q.pop();
				q.pop();
				q.push(a[j]);
			}
			else{
				q.push(a[j]);
				f[a[j]]=1;
			}
		}
		while(q.size()!=0) {
			t[q.top()]++;
			q.pop();
		}
	}
	for(int i=1;i<=m;i++) {
		cout<<t[i];
		if(i!=m) cout<<" ";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
