#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long arr[500005];
priority_queue< long long ,vector< long long >,greater< long long > > q;
queue<long long> qqq;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	int big=1;
	for(long long i=1;i<=n;i++){
		cin>>arr[i];
		q.push(arr[i]);
	}
	int qq=n;
	long long num=1;
	while(m--){
		long long sh=q.top();	
		long long f=q.top();
		q.pop();
		q.push(f+1);
		while(qq--){
			qqq.push(q.top());
			q.pop();
			if(q.top()!=sh){
				if(big<num){
					big=num;	
					num=1;
				}
			}
			sh=q.top();
			num++;
		}
		num=0;
		qq=n;
		while(!qqq.empty()){
			q.push(qqq.front());
			qqq.pop();
		}
	}
	cout<<big;
	return 0;
}
