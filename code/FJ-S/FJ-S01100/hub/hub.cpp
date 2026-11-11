#include<bits/stdc++.h>
using namespace std;

int c,t,n,k;
vector<int> mp[1000005];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			mp[u].push_back(v);
			mp[v].push_back(u);
		}
		cout<<t<<"\n";
	}
	return 0;
}
/* 
咋这难TT
依旧最后一题毫无思路，连暴力都不会，嘎巴一下死这里了，回家种田了 
最后一次参赛了，退役了 
bro笑死了，考场上写这种东西，回去就把这段代码发朋友圈 

rp++佛祖保佑妈祖保佑菩萨保佑
哎你说会不会有人看到这段话 

四小时过的好快，谁来救救我。。。 

距离考试结束还有五分钟 
*/
