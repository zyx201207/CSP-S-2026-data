#include<bits/stdc++.h>
using namespace std;
int n,m;
int cd[500010];
int cnt[300010];
int v[300010];
int t=1;
void push(int e){
	v[t]=e;
	t++;
}
void del(int i){
	for(int k=i;k<=t;k++)v[k]=v[k+1];
	t--;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>cd[i];
	for(int i=1;i<=n;i++){
		memset(v,0,sizeof(v));
		for(int j=i;j<=n;j++){
			for(int k=1;k<=t;k++){
				if(v[k]==cd[j]){
					while(v[k]!=0)del(k);
				}
			}
			push(cd[j]);
		}
		for(int i=1;i<=t;i++){
			cnt[v[i]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<cnt[i]<<" ";
	}
	return 0;
}
