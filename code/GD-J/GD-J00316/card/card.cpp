#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m;cin>>n>>m;
	vector<int> a(n+1);

	for(int i=1;i<=n;i++) cin>>a[i]; 
	
	vector<int> qc(m+1);
	stack<int> q;
	vector<int> ans(m+1,0);
	stack<int> q2;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++) qc[j]=0;
		 
		
		for(int j=i;j<=n;j++){
			if(qc[a[j]]==1){
				int cd=q.size();
				for(int z=1;z<=cd;z++){
					
					if(q.top()==a[j]){
						q.pop();
						break;
					}
					else{
						qc[q.top()]=0;
						q.pop();
					}
				}
				
				q.push(a[j]);
			}
			else{
				q.push(a[j]);
				qc[a[j]]=1;
			}

		}
		
		while(!q.empty()){
			
			ans[q.top()]++;
			q.pop();
		}
	
	} 
	
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
} 

