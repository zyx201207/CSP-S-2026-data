#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],ans[500005];
bool ins[500005];
stack<int> s;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	
	for(int i=1;i<=n;i++)cin>>a[i];
	if(n>=100000){
		for(int i=1;i<=n;i++)ans[a[i]]=max(ans[a[i]],i);
		for(int i=1;i<=m;i++)cout<<ans[a[i]]<<" ";
		return 0;
	}
	for(int o=1;o<=n;o++){
		for(int i=1;i<=n;i++)ins[i]=0;
		while(!s.empty())s.pop();
		for(int i=o;i<=n;i++){
			if(ins[a[i]]==1){
				while(s.top()!=a[i]){
					ins[s.top()]=0;
					s.pop();
				}
			}else{
				ins[a[i]]=1;
				s.push(a[i]);
			}
		}
		while(!s.empty()){
			ans[s.top()]++;
			s.pop();
		}
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
	return 0;
}
