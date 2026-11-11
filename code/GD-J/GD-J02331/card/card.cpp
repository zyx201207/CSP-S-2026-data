#include<bits/stdc++.h>
using namespace std;
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin.tie(nullptr)->sync_with_stdio(false);
	srand(time(0));
	int n;
	cin>>n;
	while(n--)cout<<rand()%n<<' ';
	return 0;
}
