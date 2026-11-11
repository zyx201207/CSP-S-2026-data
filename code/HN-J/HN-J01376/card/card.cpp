#include<bits/stdc++.h>
using namespace std;
#define int long long

int n,m;
int a[500005];
int b[300005];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	
	int turn=0;
	while(turn+1<=n){
		vector<int> v;
		queue<int> q;
		int w=0;
		bool op=false;
		int now;
		for(int i=turn;i<n;i++){
			now=a[i];
//			cout<<"now"<<a[i];
			if(v.size()){
				for(int j=w;j<v.size();j++){
					if(v[j]==now){
						while(q.size()){
							q.pop();
						}
						q.push(now);
						w=j+1;
						op=true;
						break;
					}
				}
			}
			if(op){
				op=false;
				continue;
			}
			q.push(now);
			v.push_back(a[i]);
		}
		
		while(q.size()){
			b[q.front()]++;
			cout<<q.front()<<" ";
			q.pop();
		}
		cout<<endl;
		turn++;
	}
	
	for(int i=1;i<=m;i++){
		cout<<b[i]<<" ";
	}
	return 0;
}
