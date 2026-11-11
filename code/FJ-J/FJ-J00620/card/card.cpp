#include<bits/stdc++.h>
using namespace std;
int n,m,a[500001],b[300001];
bool c[300001];
stack<int>s;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		memset(c,0,sizeof(c));
		for(int j=i;j<=n;j++){
			if(c[a[j]]==0){
				s.push(a[j]);
				c[a[j]]=1;
			}else{
				while(s.top()!=a[j]){
					c[s.top()]=0;
					s.pop();
				}
			}
		}
		while(!s.empty()){
			b[s.top()]++;
			s.pop();
		}
	}
	for(int i=1;i<=m;i++){
		cout<<b[i]<<' ';
	}
	return 0;
}
