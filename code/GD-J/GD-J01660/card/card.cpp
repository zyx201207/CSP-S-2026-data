#include<bits/stdc++.h>
using namespace std;
const int M= 5e5+5,MM=3e5+5;
int n,m;
int a[M],ans[M];
stack<long long>s;
void solutionnn(int fromxxx)
{	
	
	bool vis[MM];
	for(int i=fromxxx;i<=n;i++){
		if(vis[a[i]]==1){
			while(s.top()!=a[i]){			// return value 3221225477
				vis[s.top()]=0;				// return value 3221225477
				s.pop();					// return value 3221225477
			}
			
		}
		else{
			s.push(i);				
			vis[i]=1;
		}
	}
	while(!s.empty()){
		ans[s.top()]++;
	}
	
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
for(int i=1;i<=m;i++)		//万一我运气真的很好呢？ 
cout<<rand()%200 ;
}
}
