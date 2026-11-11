#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int a[N];
int ans[N];
int main(){//rp++
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}		
	for(int i=1;i<=n;i++){
		vector<int> board;
		board.resize(0);
		for(int j=i;j<=n;j++){
			int flag=-1;
			for(int k=0;k<board.size();k++){
				if(board[k]==a[j]){flag=k;break;}
			}
			if(flag!=-1)
				board.resize(flag);
			board.push_back(a[j]);
		}
		for(auto& e:board){
			ans[e]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
	return 0;
} 
/*
10 3
3 1 2 1 3 2 3 1 2 1

*/
