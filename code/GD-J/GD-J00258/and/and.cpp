#include<iostream>
#include<utility>
#include<algorithm>
#include<queue>
#define int long long
using namespace std;
queue<int> que,que1,cmp,clea;
int a[200005];
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,ans=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		que.push(a[i]);
	}
	for(int i=30;i>=0;i--){
		cmp=que;
		while(!cmp.empty()){
			int p=cmp.front();
			cmp.pop();
			if((p&(1ll<<i))!=0){
				//cout<<p<<" ";
				que1.push(p);
			} 
		}
		if(que1.size()>=m){
			que=que1;
		}
		que1=clea;
		//cout<<que.size()<<" ";
	}
	int num=-1;
	while(!que.empty()&&m--){
		int p=que.front();
		que.pop();
		if(num==-1) num=p;
		else num=(num&p);
	}
	cout<<num;
	return 0;
} 
//1111 1100
