#include<bits/stdc++.h>
using namespace std;
int n,m;
int deck[500005];
int lst[500005];
int board[500005];
int ans[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout); 
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>deck[i];
	}
	for(int i=1;i<=n;i++){
//		cerr<<"turn "<<i<<": "<<endl;
		for(int j=1;j<=m;j++){
			lst[j]=0;
		}
		int k=1;
		for(int j=1+i-1;j<=n;j++){
			if(lst[deck[j]]!=0 && lst[deck[j]]<k){
				for(int p=1;p<=m;p++){
					if(lst[p]>lst[deck[j]] && lst[p]<k){
						lst[p]=0;
						for(int u=lst[deck[j]];u>=1;u--){
							if(board[u]==p){
								lst[p]=u;
								break;
							}
						}
					}
				}
				k=lst[deck[j]];
//				cerr<<"put "<<deck[j] <<" and bang, k="<<lst[deck[j]]<<endl;
			}else{
				lst[deck[j]]=k;
				board[k]=deck[j];
//				cerr<<"put "<<deck[j]<<endl;
			}
//			cerr<<"now: ";
//			for(int u=1;u<=k;u++){
//				cerr<<board[u]<<" ";
//			}cerr<<endl;
			k++;
		}
//		cerr<<"end: ";
		for(int j=1;j<k;j++){
//			cerr<<board[j]<<" ";
			ans[board[j]]++;
		}
//		cerr<<endl;
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
}
