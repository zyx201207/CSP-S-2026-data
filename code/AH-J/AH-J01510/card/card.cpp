#include<bits/stdc++.h>
using namespace std;
int n,m,a[500010],ans[300010];
bool appeared[300010];
stack<int>s;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=n;i>=1;i--)cin>>a[i];
	for(int i=1;i<=n;i++){
		while(!s.empty())s.pop();
		memset(appeared,0,sizeof(appeared));
		for(int j=i;j<=n;j++){
			if(appeared[a[j]]){
				while(s.top()!=a[j]){
					appeared[s.top()]=0;
					s.pop();
				}
			}else{
				s.push(a[j]);
				appeared[a[j]]=1;
			}
		}
		for(int j=1;j<=m;j++)ans[j]+=appeared[j];
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
	return 0;
}
