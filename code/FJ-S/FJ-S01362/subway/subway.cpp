#include<bits/stdc++.h>
using namespace std;
int w[500005];
int flag[500005];
int a[500005],t[500005];
priority_queue<pair<int,int>> q2;
struct node {
	int to,len;
};
vector<node> tu[500005];
int main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1; i<=m; i++) {
		cin>>w[i];
	}
	int new1=m+1;
	for(int i=1; i<=n; i++) {
		int k;
		cin>>k;
		for(int j=1; j<=k; j++) {
			cin>>a[j]>>t[j];
		}
		for(int j=1; j<=k; j++) {
			tu[a[j]].push_back(node{new1,t[j]});
			tu[new1].push_back(node{a[j],t[j]});
			if(j!=k) {
				tu[new1].push_back(node{new1+1,0});
			}
			new1++;
		}
	}
	for(int i=1; i<=q; i++) {
		int l,r;
		cin>>l>>r;
		q2.push({0,l});
		while(!q2.empty()) {
			int t1=q2.top().first;
			int t2=q2.top().second;
			q2.pop();
			if(t2==r) {
				cout<<-t1+w[l]+w[r]<<endl;
				break;
			}
			flag[t2]=1;
			for(int j=0; j<tu[t2].size(); j++) {
				if(flag[tu[t2][j].to]==0) {
					q2.push({t1-tu[t2][j].len,tu[t2][j].to});
				}
			}
			
		}
		while(!q2.empty()) {
			q2.pop();
		}
		for(int j=0;j<=new1+100;j++){
			flag[j]=0;
		}
	}
	return 0;
}