#include<bits/stdc++.h>
using namespace std;
int n,m,a[500010],b[300010],c[300010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		stack<int> s;
		for(int j=i;j<=n;j++){
			if(c[a[j]]==0){
				s.push(a[j]);
				c[a[j]]+=1;
			}else{
				while(s.top()!=a[j]){
					c[s.top()]=0;
					s.pop();
				}
			}
		}
		for(int j=1;j<=m;j++){
			if(c[j]==1){
				b[j]++;
			}
		}
		memset(c,0,sizeof(c));
	}
	for(int i=1;i<=m;i++){
		cout<<b[i]<<" ";
	}
	return 0;
}
