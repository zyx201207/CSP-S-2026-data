#include<bits/stdc++.h>
using namespace std;


int a[500010]={0};//第i张牌是什么 
int b[300005]={0};//每种牌留下的个数

int n,m;

void game(int l,int r){
	bool p[300005]={false};
	int k[300005]={0};
	for(int i=l;i<=r;i++){
		if(!p[a[i]]) {
			p[a[i]]=true;
			k[a[i]]=i;
		}
		else {
			for(int j=k[a[i]];j<=i;j++){
				p[a[j]]=false; 
			}
			p[a[i]]=true;
		}
	}
	for(int i=1;i<=m;i++){
		if(p[i]) b[i]++; 
	}
} 


int main(){
	
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	cin>>n>>m;
	
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		game(i,n);
	}
	for(int i=1;i<=m-1;i++){
		cout<<b[i]<<' '; 
	}
	cout<<b[m]; 
	return 0;
}
