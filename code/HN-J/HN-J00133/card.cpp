#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],b[300005],ans[300005];
stack<int> x;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		memset(b,0,sizeof(b+m+1));
		for(int j=i;j<n;j++){
			if(!b[a[j]]){
				x.push(a[j]);
				b[a[j]]=1;
			}else{
				while(x.top()!=a[j]){
					b[x.top()]=0;
					x.pop();
				}
			}
		}
		while(!x.empty()){
			ans[x.top()]++;
			x.pop();
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
	return 0;
}
