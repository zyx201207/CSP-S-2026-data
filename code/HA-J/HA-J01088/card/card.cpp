#include <bits/stdc++.h>
using namespace std;
const int N=5e5;
const int M=3e5;
int n,m;
vector<int>v;
int barrel[M];
pair<int,int>l[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		v.push_back(x);
	}
	for(int i=0;i<n;i++){
		int cnt=0;
		int head=0;
		l[cnt].first=v[i];
		l[cnt++].second=-1;
		for(int j=i+1;j<n;j++){
			int last=-1,now=head;
			while(l[now].first!=v[j]&&l[now].second!=-1){
				last=now;
				now=l[now].second;
			}
			if(l[now].first==v[j]){
				if(last==-1){
					head=cnt;
				}else{
					l[last].second=cnt;
				}
			}else{
				l[now].second=cnt;
				
			}
			l[cnt].first=v[j];
			l[cnt++].second=-1;
		}
		int t=head;
		while(t!=-1){
			barrel[l[t].first]++;
			t=l[t].second;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<barrel[i]<<" ";
	}
	return 0;
}
