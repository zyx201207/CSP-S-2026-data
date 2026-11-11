#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
	cin.tie(0);
	cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,a[500005]={};
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int ans[300005]={};
	for(int i=0;i<n;i++){
		
		stack<int> s;
		int b[300005]={};
		for(int j=i;j<n;j++){
			
			if(b[a[j]]==1){
				while(!s.empty()&&s.top()!=a[j]){
					s.pop();
				}
				if(!s.empty()){
					s.pop();
				}
				
				s.push(a[j]);
			}
			else{
				s.push(a[j]);
				b[a[j]]=1;
			}
		}
		while(!s.empty()){
			ans[s.top()]++;
			s.pop();
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
	return 0;
}
