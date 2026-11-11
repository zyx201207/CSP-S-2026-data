#include<bits/stdc++.h>
using namespace std;
map<pair<int,int>,int>line;
vector<int>s[500001];
int w[500001],t[500001][501];
int main(){
 	freopen("subway.in","r",stdin);
 	freopen("subway.out","w",stdout);
 	ios::sync_with_stdio(false);
 	cin.tie(0);
 	int c,n,m,d,q;
 	cin>>c>>n>>m>>d>>q;
 	for(int i=0;i<m;i++){
 		cin>>w[i];
	 }
	 for(int i=0;i<n;i++){
	 	int k;
	 	cin>>k;
		 for(int j=0;j<k;j++){
			int a;
			cin>>a>>t[a][i];
			s[a].pushback(i);
			if(s[a].size()>=2)
				for(int p=0;p<s[a].size()-1;p++){
					line[s[a][p]][l]=min(line[s[a][p]][l],t[a][s[a][p]]+t[a][i]);
				}
			sort(s[a],s[a]+s[a].size());
		 }
	 }
	 for(int i=0;i<q;i++){
	 	int fro,to,time;
	 	cin>>fro>>to;
	 	time+=(w[fro]+w[to]);
	 	cout<<time; 
	 }
 	return 0;
}
