#include<bits/stdc++.h>//0
using namespace std;
const int N=5e5,M=3e5;
int a[N];
int ans[M];
bool card[M];
int n,m;
void play(){//???
	for(int i=1;i<=n;i++){
		if(card[a[i]]){
			memset(card,1,sizeof card);
			card[a[i]]=true;
		}else{
			card[a[i]]=true;
		}
	}
	for(int i=1;i<=m;i++){
		if(card[i])ans[i]++;
	}
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout); 
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=m;i++){
		play();
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	} 
	return 0;
} 
