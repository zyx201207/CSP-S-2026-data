#include<iostream>
#include<stack>
#include<cstring>
using namespace std;
int n,m,a[500005];
bool isin[5005];
int ans[500005];
stack<int> s;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<=5000){
		for(int i=1;i<=n;i++){
			memset(isin,0,sizeof(isin));
			for(int j=i;j<=n;j++){
				if(isin[a[j]]){
					while((!s.empty())&&s.top()!=a[j]){
						isin[s.top()]=0;
						s.pop();
					} 
				}else{
					s.push(a[j]);
					isin[a[j]]=1;
				}
			}
			for(int j=1;j<=m;j++){
				ans[j]+=isin[j];
			}
			while(!s.empty()) s.pop();
		}
		for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
	}else{
		for(int i=1;i<=m;i++){
			cout<<i;
		}
	}
	return 0;
} 
