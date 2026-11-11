#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],b[300005],s[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		stack<int>q;
		memset(b,0,sizeof(b));
		for(int j=i;j<=n;j++){
			if(b[a[j]]==1){
				while(q.top()!=a[j]) q.pop();
			}else{
				q.push(a[j]);
				b[a[j]]++;
			}
		}
		while(!q.empty()){
			int l=q.top();
			q.pop();
			s[l]++;
		}
	}
	for(int i=1;i<=m;i++) cout<<s[i]<<' ';
	return 0;
} 
