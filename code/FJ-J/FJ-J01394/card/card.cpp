#include<bits/stdc++.h>
using namespace std;
int a[500005],b[300005],ans[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(m==1){
		cout<<n;
		return 0;
	}
	stack<int> q;
	for(int i=1;i<=n;i++){
		memset(b,0,sizeof(b));
		for(int j=i;j<=n;j++){
			if(b[a[j]]==0){
				b[a[j]]++;
				q.push(a[j]);	
			}
			else{
				while(1){
			
					if(q.top()==a[j]) break;
					b[q.top()]--;
					q.pop();
				}
			}
		}
		while(!q.empty()){
			ans[q.top()]++;
			q.pop();
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
