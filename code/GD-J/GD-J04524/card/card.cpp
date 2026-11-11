#include<bits/stdc++.h>
using namespace std;
int n,m,board[50005],tot[30005],card[50005],have[50005],havepos[50005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout); 
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>card[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=50005;j++){
			have[j]=0;
			havepos[j]=0;
		}
		for(int j=i;j<=n;j++){
			if(have[card[j]]==1){
				for(int k=havepos[card[j]];k<=j;k++){
					board[k]=0;
				}
				board[havepos[card[j]]]=card[j];
			}else{
				board[j-i+1]=card[j];
				have[card[j]]=1;
				havepos[card[j]]=j-i+1;
			}
		}
		for(int j=1;j<=n-i+1;j++){
			tot[board[j]]++;
		}
		
	}
	for(int j=1;j<=m;j++){
		cout<<tot[j]<<' ';
	}
	return 0;
}
