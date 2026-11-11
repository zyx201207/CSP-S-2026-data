#include<bits/stdc++.h>
using namespace std;


long long M[50005];
long long dp[505][505];

long long at_to_un[50005][505];

struct node{
	int ip;
	int out;
};
vector<node> N[505];
vector<int> M_under[50005];

int c,n,m,d,q;

struct st{
	int ip;
	int time;
};
vector<st> Set;
int hard = 1;

void dij(int stra,int end){
	
	Set.clear();
	hard = 0;
	Set.push_back({stra,0});
	
	while(Set.size() > hard){
		
		st temp = Set[hard];
		hard++;
		
//		cout<<"t: "<<temp.ip<<" "<<temp.time<<endl;
		
		for(int i = 0; i < N[temp.ip].size(); i++){
			
			int stanp = N[temp.ip][i].ip;
			
			for(int j = 0; j < M_under[stanp].size(); j++){
				
				int under = M_under[stanp][j];
				
				if( under == temp.ip){
					continue;
				}
				
//				cout<<stra<<" "<<stanp<<" "<<under<<" "<<temp.ip<<endl;
				
				int time = temp.time + at_to_un[stanp][temp.ip] + at_to_un[stanp][under]; 
				
				
				if(dp[temp.ip][under] > time && dp[under][temp.ip] > time){
					dp[temp.ip][under] = time;
					dp[under][temp.ip] = time;
					Set.push_back({under,time});
					
					
				}
//				cout<<"dp: "<<temp.ip<<" "<<under<<endl;
//				cout<<dp[temp.ip][under]<<" "<<time<<endl;
			}
			
		}
		cout<<endl;
	}
	
	
}

//long long dfs(int start, int end, long long time){
//	
//	if(start == end){
//		return 0;
//	}
//	
//	for(int t = 0; t < N[start].size(); t++){
//		int at = N[start][t].ip;
//		
//		for(int i = 0; i < M_under[at].size(); i++ ){
//			
//			int ather = M_under[at][i];
//			
//			if(ather == start){
//				continue;
//			}
//			
//			
//			dp[start][ather] = min(dp[start][ather],at_to_un[at][start] + at_to_un[at][ather]);
//			
//			if(ather == end){
//				return dp[start][end];
//			}
//			
//			dp[start][end] = min(dp[start][end],dfs(ather,end,time + dp[start][ather]));
//		}
//		
//	}
//	
//
//}


int main(){
	
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	cin>>c>>n>>m>>d>>q;
	
	for(int i = 1;i <= m; i++){
		cin>>M[i];
	}
	
	for(int i = 1; i <= n; i++){
		int k;
		cin>>k;
		
		for(int j = 1;j <= k; j++){
			int a,t;
			
			cin>>a>>t;
			
			M_under[a].push_back({i});
			N[i].push_back({a,t});
			at_to_un[a][i] = t;
			
		}
		
	}
	
	for(int i = 1; i <= n; i++){
		for(int j = i; j <= n; j++){
			
			dp[i][j] = 0x3f3f3f3f3f;
			dp[j][i] = 0x3f3f3f3f3f;
		}
	}
	
	for(int i = 1; i < n; i++){
		for(int j = i + 1; j <= n; j++){
			
			dij(i,j);
			
		}
	}
	
//	for(int i = 1; i <= n; i++){
//		for(int j = 1; j <= n; j++){
//			
//			if(dp[i][j] == 0x3f3f3f3f3f){
//				cout<<"X "; 
//				continue;
//			}
//			cout<<dp[i][j]<<" ";
//		}
//		cout<<endl;
//	}
	
//	for(int i = 1; i <= q; i++){
//		int x,y;
//		cin>>x>>y; 

	return 0;
}
/***
0 2 4 2 1
1 1 1 1
3 1 1 2 1000 3 1
2 3 1 4 1

0 5 5 2 1
1 1 1 1 1
2 1 1 2 1
2 4 1 5 1
2 1 100 4 100
2 2 1 3 1
2 3 1 5 1
***/


