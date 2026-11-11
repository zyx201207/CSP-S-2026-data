#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005];
int ans[300005];
stack<int> k;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		bool b[300005]={0};
		for(int j=i;j<=n;j++){
			if(b[a[j]]==0){
				b[a[j]]=1;
				k.push(a[j]);
			}else{
				while(k.top()!=a[j]){
					b[k.top()]=0;
					k.pop();
				}
			}
		}
		while(!k.empty()){
			ans[k.top()]++;
			k.pop();
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
} 
