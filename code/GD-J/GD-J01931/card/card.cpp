#include<bits/stdc++.h>
#define int long long
using namespace std;
deque<int>q;
int n,m,a[505],bx[3005];
bool check(int k){
	int p=q.size();
	bool flag=0;
	for(int i=1;i<=p;i++){
		if(q.front()==k)flag=1;
		q.push_back(q.front());
		q.pop_front(); 
	}
	return flag;
}
int find(int k){
	int cnt=0,p=q.size();
	bool flag=0;
	for(int i=1;i<=p;i++){
		if(q.front()==k)flag=1;
		if(flag==0)cnt++;
		q.push_back(q.front());
		q.pop_front();
	}
	return cnt;
}
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(j<=i-1)continue;
			int f=find(a[j])-1,k=q.size()-f;
			if(check(a[i])){
				while(f--){
					q.push_back(q.front());
					q.pop_front();
				}
				while(k--)q.pop_front();
			}
			q.push_back(a[j]);
		}
		while(!q.empty()){
			cout<<q.front()<<' ';
			bx[q.front()]++;
			q.pop_front();
		}
		cout<<endl;
	}
	for(int i=1;i<=m;i++)cout<<bx[i]<<' ';
	return 0;
}
