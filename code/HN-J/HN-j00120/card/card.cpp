#include<bits/stdc++.h>
using namespace std;
int n,m,gr[300010],cards[300010],ans[300010];
queue<int>hand;
int main(){
//	freopen("cards.in","r",stdin);
//	freopen("cards.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		hand.push(x);
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			gr[i]=0;
			cards[i]==0;
		}
		for(int i=1;i<=n-k;i++){
			int x=hand.front();
			hand.pop();
			hand.push(x);
			if(cards[x]){
				int j=cards[x]+1;
				while(1){
					if(gr[j]==0)break;
					gr[j]=0;
					cards[j]=0;
					j++;
				}
			}else{
				cards[x]=i;
				gr[cards[x]]=x;
			}
		}
		cout<<cards[1]<<' ';
		cout<<endl;
		for(int i=1;i<=m;i++){
			if(cards[i]!=0)ans[i]++;
		}
		hand.pop();
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
	return 0;
} 
