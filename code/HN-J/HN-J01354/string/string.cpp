#include<bits/stdc++.h>
using namespace std;
stack<char> q;
int n,ans,sum;
queue<char> p;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	int x;
	char y;
	for(int i=1;i<=n;i++){
		cin>>x>>y;
		sum+=x;
		for(int j=1;j<=x;j++){
		p.push(y);
	}
	}
    for(int i=1;i<=(sum+1)/2;i++){
    	q.push(p.front());
    	p.pop();
	}
	if(sum%2==1) q.pop();
	for(int i=1;i<=sum/2;i++){
		if(q.top()!=p.front()) ans++;
		q.pop();
		p.pop(); 
	}
	cout<<ans;
	return 0;
} 
