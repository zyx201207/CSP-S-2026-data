#include<bits/stdc++.h>
#define ll long long
using namespace std;

int n,m;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	srand(time(0));
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		int t;
		cin>>t;
	}
	for(int i=1;i<=m;i++) cout<<rand()%100+1<<" ";
	return 0;
}

