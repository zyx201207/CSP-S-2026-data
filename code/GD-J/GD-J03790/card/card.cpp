#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,m,a[N],flag[N],num[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++){
		stack<int> q;
		for(int j=i;j<=n;j++){
			if(flag[a[j]]==0){
				flag[a[j]]=1;
				q.push(a[j]);
			}else if(flag[a[j]]==1){
				while(!q.empty()){
					if(q.top()==a[j]){
						q.pop();
						break;
					}
					flag[q.top()]=0;
					q.pop();
				}
				q.push(a[j]);
			}
		}
		while(!q.empty()){
			num[q.top()]++;
			q.pop();
		}
		for(int j=1;j<=m;j++)
			flag[j]=0;
	}
	for(int i=1;i<=m;i++)
		cout<<num[i]<<" ";
	return 0;
}
