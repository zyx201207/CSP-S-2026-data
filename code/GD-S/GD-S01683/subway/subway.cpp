#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;//Rt
int w[500002]/*jin\ chu- zhan\*/,in1,in2,k[500002],x,y;
vector<pair<int,int>> s[500002];//stations
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	for(int i = 0;i < m;i++){
		cin >> w[i];
	}
	for(int i = 0;i < n;i++){
		cin >> k[i];
		for(int j = 0;j < k[i];j++){
			cin >> in1 >> in2;
			s[in1].push_back(make_pair(i,in2));
		}
	}
	while(q--){
		cin >> x >> y;
	}
	return 0;
}
