#include<bits/stdc++.h>
using namespace std;
int n,m,r,a[500005],ans[500005],w[500005];
deque<int>q,qq,qqq;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i]; 
		q.push_back(a[i]);
	} 
	int t=0;
	for(int i=1;i<=n;i++){
		int cnt=0;
		while(cnt!=n-i+1){
			int k=q.front();
			q.pop_front();
			while(qq.size()&&qq.front()!=k){
				qqq.push_back(qq.front());
				qq.pop_front();
			}
			while(qq.size()){
				q.push_back(qq.front());
				qq.pop_front();
			}
			while(qqq.size()){
				qq.push_back(qqq.front());
				qqq.pop_front();
			}
			qq.push_back(k);
			cnt++;
		}
		while(qq.size()){
			q.push_back(qq.front());
			ans[qq.front()]++;
			qq.pop_front();
		}
		while(q.size()!=n-i){
			q.pop_front();
		}
//		print();
//		cout<<endl;
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
/*
4 3
1 2 1 3

10 3
3 1 2 1 3 2 3 1 2 1
*/
