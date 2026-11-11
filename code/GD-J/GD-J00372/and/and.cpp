#include<bits/stdc++.h>
using namespace std;
priority_queue<pair<int,int>>q;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		int xx=x;
		int cnt=0;
		while(x){
			if(x&1){
				cnt++;
			}
			x/=2;
		}
		q.push({cnt,xx});
	}
	int now_x=q.top().second;
	q.pop();
	for(int i=2;i<=m;i++){
		now_x&=q.top().second;
		q.pop();
	}
	cout<<now_x;
	return 0;
}
