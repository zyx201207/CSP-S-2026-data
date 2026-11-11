#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
const int M=1e5+10;
int n,m;
int a[N],sum[10009];
bool flag[M];

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		memset(flag,0,sizeof(flag));
		stack<int> q;
		for(int j=i;j<=n;j++){
			if(flag[a[j]]==false){
				flag[a[j]]=true;
				q.push(a[j]);
			}else{
				while(q.top()!=a[j]){
					flag[q.top()]=false;
					q.pop();
				}
				q.pop();
				q.push(a[j]);
				flag[a[j]]=true;
			}
		}
		while(!q.empty()){
			sum[q.top()]++;
			q.pop();
		}
	}
	for(int i=1;i<=m;i++){
		cout<<sum[i]<<' ';
	}
	return 0;
}
