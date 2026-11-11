#include<bits/stdc++.h>
using namespace std;
int arr[300100],ans[300100];
bool card[300100];
void solve(int n,int m,int i){
	cout<<i<<endl;
	memset(card,false,sizeof(card));
	stack <int> table;
	for(;i<=n;i++){
		if(card[arr[i]]){
			while(table.top()!=arr[i]){
				card[table.top()]=false;
				table.pop();
			}
		}else{
			table.push(arr[i]);
			card[i]=true;
		}/*for(int j=1;j<=m;j++){
			cout<<card[j]<<":"<<j<<" ";
		}cout<<endl;*/
	}
	while(table.size()){
		ans[table.top()++];
		table.pop();
	}
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout); 
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
	}
	for(int i=1;i<=n;i++){
		solve(n,m,1);
	}for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
