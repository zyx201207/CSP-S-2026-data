#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],b[300005],c[300005];
stack <int> q;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>n;
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(b[a[j]]==0){
				q.push(a[j]);
				b[a[j]]=1;
			}
			else{
				while(q.top()!=a[j]){
					b[q.top()]=0;
					q.pop();
				}
			}
		}
		while(!q.empty()){
			c[q.top()]++;
			q.pop();
		}
	}
	for(int i=1;i<=m;i++) cout<<c[i]<<' ';
	return 0;
}
