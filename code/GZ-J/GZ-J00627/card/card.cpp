//GZ-J00627 ·¶Ώ£γρ 
#include <bits/stdc++.h>
using namespace std;

int card[500001];
int next[500001];
int ans[300001];
int m,n;

void play(int x){
	for(int i=x;i<=m;i++){
		if(next[i]!=0){
			i=next[i]-1;
		}
		else{
			ans[card[i]]++; 
			//cout<<i<<' ';
		} 
		
	}
}

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin.tie(0);
	cin>>m>>n;
	for(int i=1;i<=n;i++){
		ans[i]=0;
	}
	for(int i=1;i<=m;i++){
		next[i]=0;
	}
	for(int i=1;i<=m;i++){
		cin>>card[i];
		if(ans[card[i]]==0){
			ans[card[i]]=i;
		}
		else{
			next[ans[card[i]]]=i;
			ans[card[i]]=i;
		}
	}
	for(int i=1;i<=n;i++){
		ans[i]=0;
	}
	for(int i=1;i<=m;i++){
		play(i);
		
	}
	for(int i=1;i<=n;i++){
		cout<<ans[i]<<' ';
	}
	return 0;
}
