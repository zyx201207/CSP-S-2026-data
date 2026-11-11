#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	srand(time(0));
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=m;i++) cout<<rand()%n+1<<' ';
	return 0;
}

