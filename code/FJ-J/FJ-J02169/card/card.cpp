#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],h[300005],ans[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		memset(h,0,sizeof(h));
		stack<int>s;
		for(int j=i;j<=n;j++){
			if(h[a[j]]==0){
				s.push(a[j]);
				h[a[j]]=1;
			}
			else{
				while(s.top()!=a[j]){
					h[s.top()]=0;
					s.pop();
				}
			}
		}
		while(!s.empty()){
			ans[s.top()]++;
			s.pop();
		} 
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
	return 0;
}
