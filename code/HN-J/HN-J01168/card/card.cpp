#include<bits/stdc++.h>
using namespace std;

int n,m,a[500050],b[300050],f[300050];
bool c[30050];

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int e=1;e<=n;e++){
		stack<int> s;
		memset(b,0,sizeof b);
		memset(c,0,sizeof c);
		for(int i=e;i<=n;i++){
			if(b[a[i]]==1){
				while(s.top()!=a[i]){
					b[s.top()]--;
					s.pop();
				}
			}else b[a[i]]++,s.push(a[i]);
		}
		while(s.size()){
			if(!c[s.top()])c[s.top()]=1,f[s.top()]++;
			s.pop();
		}
	}
	for(int i=1;i<=m;i++)cout<<f[i]<<' ';
	return 0;
}
