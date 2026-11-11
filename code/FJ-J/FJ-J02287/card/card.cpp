#include<bits/stdc++.h>
using namespace std;
void mas(){	
	int n,m;
	int a[1000];
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];	
	}for(int i=1;i<=m;i++){
		cout<<1<<" ";
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int T=1;
	//cin>>T;
	while(T--){
		mas();	
	}
	return 0;	
}
