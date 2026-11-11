#include <bits/stdc++.h>
using namespace std;
vector<bool> placed;
vector<int> table;
vector<int> ans;



int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	vector<int> a(m);
	
	for(int i=1;i<=n;i++){
		cin>>a[i];
		
	}
	placed.assign(m+5,false);
	table.assign(n+5,0);
	ans.assign(m+5,0);
	int count =1;
	for(int i=1;i<=n;i++){
		
		for(int j=i;j<=n;j++){
		
			if(placed[a[j]]==false){
				placed[a[j]]=true;
				
				table[count]=a[j];
			
				count++;
				
				
			}else{
				cout<<endl;
				while(placed[a[j]]){
					count--;
					if(table[count]!=a[j]){
						table[count]=0;
						
					}else{
					
						placed[a[j]]=false;
						count--;
					
				}
					
			
			}
			
		}
		
	}

		for(int k=1;k<=count;k++){
				ans[table[k] ]++;
				
			}
		placed.assign(m+5,false);
		table.assign(n+5,0);
		count=1;
}
	
	
	
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}











