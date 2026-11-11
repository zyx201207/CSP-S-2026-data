#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	srand(time(NULL));
	int c,t;
	cin>>c>>t;
	while(t--){
		cout<<rand()%t+1<<"\n";
	}
	return 0;
}
//freopen
/*
Luogu ID:545403 Miao
Tui yi zhi qian de zui hou yi ci csp
danshi pin jin quan li mei you xiang chu lai zen me chu li t2 de chong tu qiong kuang
zhi neng dao ci wei zhi le
ke wu a hai shi bu gan xin , ye xu wozhen de mei you tian fu ba
zai jian le , wo suo you de oi
I Love Elysia~
*/
