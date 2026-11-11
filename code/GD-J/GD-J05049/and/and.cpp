#include<bits/stdc++.h>
using namespace std;
long long n,m;
priority_queue<long long> q;
int main(){
	freopen("and.in","r",stdin);
	freopen("ans.out","w",stdout);
    cin>>n>>m;
    for(long long i = 1; i <= n; i ++){
    	long long x;
    	cin>>x;
    	q.push(x);
	}
	long long ans = 0;
    while(q.size()>1){
        long long sum = q.top(),ans1 = 0;
    	for(long long i = 1; i <= m; i ++){
    		ans1 = q.top();
    		sum&=ans1;
    		q.pop();
		}
		q.push(sum);
		ans = max(sum,ans);
	}
	cout<<ans;
	return 0;
}

