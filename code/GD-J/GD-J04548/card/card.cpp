#include<bits/stdc++.h>
#define int long long
using namespace std;
stack<int>q;
int n,m,a[500005],ans[300009],z[300006];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(z[a[j]]==1){
				while(1){
					if(q.top()==a[j]){
						z[q.top()]=0;
						q.pop();
						break;
					}else {z[q.top()]=0;q.pop();
					}
				}
				q.push(a[j]);
			}
			else {
				q.push(a[j]);
				z[a[j]]=1;
			}
		}
		while(!q.empty()){
			ans[q.top()]++;
			z[q.top()]=0;
			q.pop();
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
	return 0;
}
