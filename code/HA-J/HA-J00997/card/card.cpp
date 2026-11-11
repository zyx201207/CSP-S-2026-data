#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int n,m;
	cin>>n>>m;
	srand(time(0));
	while(m--){
		int n=rand();
		cout<<n<<' ';
	}
	return 0;
}