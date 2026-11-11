#include<bits/stdc++.h>
using namespace std;
stack<int> s;
int n,m;
int a[500001];
int ans[300001];
bool b[300001];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		memset(b,0,sizeof(b));
		for(int j=i;j<=n;j++){
			if(b[a[j]]==1){
				while(s.top()!=a[j]){
					b[s.top()]=0;
					s.pop();
				}
			}
			else{
				b[a[j]]=1;
				s.push(a[j]);
			}
		}
		while(!s.empty()){
			ans[s.top()]++;
			s.pop();
		}
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
}
