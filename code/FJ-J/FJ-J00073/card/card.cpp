#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],ans[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		bool b[300005]={};
		stack<int>s;
		for(int j=i;j<=n;j++){
			if(b[a[j]])
				while(s.top()!=a[j]){
					b[s.top()]=false;
					s.pop();
				}
			else{
				s.push(a[j]);
				b[a[j]]=true;
			}
		}
		while(!s.empty()){
			ans[s.top()]++;
			s.pop();
		}
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<' ';
	return 0;
}
