#include<bits/stdc++.h>
using namespace std;
int n,m;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	srand(time(NULL));
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
	}
	for(int i=1;i<=m;i++){
		cout<<rand()%100<<" ";
	}
	return 0;
}
