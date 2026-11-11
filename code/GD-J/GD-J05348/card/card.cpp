#include <bits/stdc++.h>
using namespace std;
long long a[500050],cnt[300050],qu[300050];     //牌、出现局数、桌面个数 
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	queue <long long> q;
	long long n,m,p=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		
	}
	for(int i=1;i<=n;i++){
		q.push(0);
		for(int j=i;j<=n;j++){
			q.push(a[j]);
			if(qu[a[j]]+1>1){
				while(p!=a[j]){
					p=q.front();
					q.pop();
				}
				p=0;
				while(p!=a[j]){
					q.pop();
					p=q.front();
				}
			}
			else qu[a[j]]++;
		}
		while(!q.empty()){
			int x=q.front();
			cnt[x]++;
			//cout<<'#'<<x;
			q.pop();
		}
		for(int i=1;i<=m;i++) qu[i]=0;
	}
	for(int i=1;i<=m;i++) cout<<cnt[i]<<' ';
	return 0;
}
