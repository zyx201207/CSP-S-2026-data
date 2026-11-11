#include<bits/stdc++.h>
using namespace std;
stack<int>p;
int cnt[300005],sum[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n+5];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			sum[a[j]]++;
			if(sum[a[j]]>=2){
				while(p.top()!=a[j]){
					p.pop();
				}
				sum[a[j]]=1;
				continue;
			}
			p.push(a[j]);
		}
		for(int j=1;j<=n;j++){
			sum[j]=0;
		}
		while(!p.empty()){
			cnt[p.top()]++;
			p.pop();
		}
	}
	for(int i=1;i<=m;i++){
		cout<<cnt[i]<<' ';
	}
	return 0;
}
