#include<bits/stdc++.h>
using namespace std;
int n,m,a[300005],b[300005],z[300005],v[300005];
stack<int>s;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++){
		memset(b,0,sizeof(b));
		for(int j=i;j<=n;j++){
			if(b[a[j]]==1){
				while(s.top()!=a[j]&&!s.empty()) b[s.top()]--,s.pop();
			}
			else s.push(a[j]),b[a[j]]++;
		}
		while(!s.empty()) z[s.top()]++,b[s.top()]--,s.pop();
	}
	for(int j=1;j<=m;j++){
		cout<<z[j]<<' ';
	}
	return 0;
} 
