#include<bits/stdc++.h>
using namespace std;

vector<int> v,game,q;

bool in_or_not(int a){
	int q=game.size();
	for(int i=0;i<q;i++)
		if(a==game[i]) 
			return 1;
	return 0;
}

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	int n,m,a;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a;
		game.push_back(a);
		q.push_back(0);
	}for(int i=0;i<n;i++){
		game={};
		for(int j=i;j<n;j++){
			if(in_or_not(v[j])){
				int e=game.size();
				while(game[e-1]==v[j])
					game.pop_back();
			}else game.push_back(v[j]);
		}for(int j=0;j<m;j++)
			if(in_or_not(j)) q[j]++;
	}for(int i=0;i<m;i++){
		cout<<q[i]<<' ';
	}
	
	/* 
	fclose("card.in",stdin);
	fclose("card.out",stdout);*/
	return 0;
} 
