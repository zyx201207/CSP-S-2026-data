#include<bits/stdc++.h>
using namespace std;
int n,m;
int  a[500010];
int b[300010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		stack<int>q;
		map<int,bool>m;
		for(int j=i;j<=n;j++){
			if(m[a[j]]==0){
				m[a[j]]=1;
				q.push(a[j]);
			}else{
				while(!q.empty()){
					if(q.top()!=a[j]){
						m[q.top()]=0;
						q.pop();
					}else{
						break;
					}
				}
				
			}
		}
		while(!q.empty()){
			//cout<<q.top()<<" ";
			b[q.top()]++;
			q.pop();
		}
		//cout<<endl;
	}
	for(int i=1;i<=m;i++){
		cout<<b[i]<<" ";
	}
	return 0;
}
