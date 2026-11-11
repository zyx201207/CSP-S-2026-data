#include <iostream>
#define mian main
#define maxn 5006
#define inf 2147483647
/*>-<*/
/*
baba is you
OI is hard
baba is sad
baba is best                  																																																																																																																																						keke on star is hot and swap baba near empty is melt rock is push level is level near rock is hot wall is melt

*/
using namespace std;

pair<int,int> dp[maxn];//first for islands and second for times

int c,t,n,m,lc[maxn];
//巧克力好吃 
int mian(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	/*
	She's a nya nya girl with a magic AK
	WDgaster told me the Knight is the mr.Rudy Holiday
	*/
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin>>c>>t;
	for(int o=0;o<t;o++){
		cin>>n>>m;
		for(int i=0;i<n;i++){
			cin>>lc[i];
		}
		bool idk=0;
		
		for(int i=0;i<maxn;i++){
			dp[i]=make_pair(inf,0); 
		}
		
		dp[0]=make_pair(1,0);
		
		for(int i=1;i<n;i++){// i forwerd!@!!!!!!! @-@; sweat inggggg
//			cout<<"finding end in "<<i<<'\n';
			for(int j=i-1;j>=0;j--){
//				cout<<"start on "<<j<<':';
				if(lc[i]-lc[j]>m) {//我在干啥来着？ 
//					cout<<"no "; 
					break;
				}
				if(dp[j].first+1 < dp[i].first){
					dp[i].first=dp[j].first+1;
					dp[i].second=1;
//					cout<<"better ";
					continue;
				}
				if(dp[j].first+1 == dp[i].first){
					dp[i].second++;
//					cout<<"plain ";
				} 
			}
//			cout<<'\n';
		}
		int ans=0;
		for(int i=0;i<n;i++){
//			cout<<i<<':'<<dp[i].first<<' '<<dp[i].second<<'\n'; 
			if(dp[i].second==2) idk=1;
			if(idk) ans++;
		}
		cout<<ans<<'\n';
	}
	
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

*/

/*

;-; <- she is sad.

|   noob   |    pro   |   hack   |   god   |
|          |          |          |         |
|          |          |          |         |
|   i=i+1; |   i++;   η   ++i;  |  i-=-1; |
|          |          |          |         |
|          |          |          |         |
|          |          |          |         |
        
        ^^^eta dan(quexin) 
        
		
piggod 懂Q密懂Q密;;;;;;;;;;;;		
*/
