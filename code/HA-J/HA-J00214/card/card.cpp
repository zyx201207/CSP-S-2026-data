#include<bits/stdc++.h>
using namespace std;
struct sss{
	int ds;
}s[300010];
int b[300010];
int a[500010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	int n,m;
	cin>>n>>m;
	
	stack<int>dp;
	
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	
	for(int j=1;j<=n;j++){
		
		for(int i=j;i<=n;i++){
			
			
			
			if(b[a[i]]==0){
				b[a[i]]++;
				dp.push(a[i]);
			}else{
				while(dp.top()!=a[i]){
					b[dp.top()]=0;
					dp.pop();
				}
			}
		}	
		
		while(!dp.empty()){
			s[dp.top()].ds++;
			dp.pop();
		}
		
		memset(b,0,sizeof(b));
	}
	
	for(int i=1;i<=m;i++){
		cout<<s[i].ds<<' ';
	}
	
	return 0;
}
