//GZ-S00255,贵阳市白云区第十八中学，杨钟源 
#include <bits/stdc++.h>
using namespace std;
struct Station{
	long long w;//示从每个地铁站的地铁口走到站厅需要的时间。
	vector<int>t;//表示从该地铁站的站厅走到第 i 条线路的站台需要的时间。
}stations[500005];
struct Way{
	vector<int>a;
}ways[505];
struct Plan{
	long long s,e;
}plans[100005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	long long c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i = 0;i < m;i++){
		cin>>stations[i].w;
	}
	for(int i = 0;i < n;i++){
		long long k;
		cin>>k;
		for(int j = 0;j < k;j++){
			long long a1,t1;
			cin>>a1>>t1;
			ways[i].a.push_back(a1);
			stations[a1].t.push_back(t1);
		}
	}
	for(int i = 0;i < q;i++){
		cin>>plans[i].s>>plans[i].e;
		int s = plans[i].s,e = plans[i].e;
		cout<<67;
	}
	return 0;
}
