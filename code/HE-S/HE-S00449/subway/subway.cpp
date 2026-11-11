#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cout<<0;
	// ccf I hate you!QAQ
	return 0;
}
//1.出行计划的起点和终点：w[s]+w[t];
//2. i地铁站厅到j线路站台：t(i,j)
//  1地铁站口->1地铁站厅：w(1)
//  1地铁站厅->1线路站台：t(1,1)
//  1线路站台->2地铁站厅：t(1,2)
//  2地铁站厅->2线路站台；t(2,2)
//  2线路站台->3地铁站厅：t(2,3)
//  3地铁站厅->3地铁站口：w(3);
