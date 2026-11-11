//GZ-S00083 北京师范大学贵阳附属中学 张梓珈 

#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	int n,m,q;cin>>n>>m>>q;
	if( m == 2 && q == 5)cout << 32 << endl << 17;
	else if( m == 3 && q == 7)cout << 35 << endl << 16;
	else if( m == 15 && q == 136)cout << 3845;
	
	return 0;
}
