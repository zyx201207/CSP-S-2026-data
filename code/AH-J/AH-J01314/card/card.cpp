#include<bits/stdc++.h>
using namespace std;
int num[300005];
int a[500005];
bool f[500005];
stack<int>q;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(f[a[j]]==0){
				q.push(a[j]);
				f[a[j]]=1;
			}else{
				while(q.top()!=a[j])f[q.top()]=0,q.pop();
			}
		}
		while(!q.empty()){
			num[q.top()]++;
			f[q.top()]=0;
			q.pop();
		}
	}
	for(int i=1;i<=m;i++)cout<<num[i]<<' ';
	return 0;
}
