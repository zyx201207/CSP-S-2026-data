#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],b[500005];
bool v[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		stack<int>s;
		memset(v,0,sizeof(v));
		for(int j=i;j<=n;j++){
			if(!v[a[j]]){
				v[a[j]]=1;
				s.push(a[j]);
			}else{
				while(s.top()!=a[j]){
					v[s.top()]=0;
					s.pop();
				}
			}
		}
		memset(v,0,sizeof(v));
		while(!s.empty()){
			if(!v[s.top()]){
				v[s.top()]=1;
				b[s.top()]+=1;
			}
			s.pop();
		}
	}
	for(int i=1;i<=m;i++){
		cout<<b[i]<<" ";
	}
	return 0;
}
