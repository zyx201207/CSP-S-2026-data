#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],b[300005],d[300005];
stack<long long> c;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(b[a[j]]==1){
				while(c.size() && c.top()!=a[j]){
					b[c.top()]=0;
					c.pop();
				}
			}else{
				b[a[j]]=1;
				c.push(a[j]);
			}
		}
		for(int i=1;i<=m;i++){
			if(b[i]==1){
				d[i]++;
			}
			b[i]=0;
		}
		while(c.size()){
			c.pop();
		}
	}
	for(int i=1;i<=m;i++){
		cout<<d[i]<<' ';
	}
}
