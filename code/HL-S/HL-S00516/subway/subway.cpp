#include <bits/stdc++.h>
using namespace std;
int c, n, m, d, q,w[505],w1,id,l,r;
struct node{
	int w,id;
};
struct node1{
	int di,step;
};
vector<node>a[505],b[505];

bool zhanting;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>> n>> m>> d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>id>>w1;
			a[i].push_back({id,w1});
		}
	}
	for(int i=1;i<=q;i++){
		cin>>l>>r;
		long long ans=0;
		ans+=w[l];
		for(int i=l+1;i<=r;i++){
			ans+=w[i]*2;
		}
		cout<<ans;
	}
	
//	for(int i=1;i<=m;i++){
//		for(int j=1;j<=a[i].size();j++){
//			cout<<a[i][j].id<<' '<<a[i][j].w<<' ';
//		}
//		cout<<endl;
//	}
//	for(int i=1;i<=q;i++){
//		queue<node1>q;
//		long long ans=0;
//		cin>>l>>r;
//		q.push({l,w[l]});
//		while(!q.empty()){
//			node1 t=q.front();
//			q.pop();
//			if(t.di==r&&t.step<ans){
//				ans=t.step;
//			}
//			for(int j=1;j<=a[t.di].size();j++){
//				//cout<<a[t.di][j].id<<' ';
//				q.push({a[t.di][j].id,t.step+a[t.di][j].w+w[a[t.di][j].id]});
//			}
//			
//		}
//		cout<<ans<<endl;
//	}
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/