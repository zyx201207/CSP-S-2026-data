#include<bits/stdc++.h>
using namespace std;
int board[300005] = {},pos[300005] = {},ans[300005] = {},card[500005] = {};
int n,m,p = 1;
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>card[i];
	for(int k=1;k<=n;k++){
		memset(board,0,sizeof(board));
		memset(pos,0,sizeof(pos));
		p=1;
		for(int i=k;i<=n;i++){
			int l = card[i];
			if(pos[l] == 0){
				pos[l] = p;
				board[p] = l;
				p++;
			}else{
				for(int j=pos[l]+1;j<=p;j++){
					pos[board[j]] = 0;
					board[j] = 0;
				}
				p = pos[l]+1;
			}
		}for(int j=1;j<p;j++)ans[board[j]]++;
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
	return 0;
}

