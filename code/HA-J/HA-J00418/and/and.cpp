#include<bits/stdc++.h>
using namespace std;
int sum=0;
int n,m;
priority_queue<int>q;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	int x;
	for(int i=1;i<=n;i++){
		cin>>x;
		q.push(x);
	}
    for(int i=1;i<=m;i++){
    	if(i==1)sum=q.top();
    	else sum=sum&q.top();
    	q.pop();
	}
	cout<<sum<<endl;
	return 0;
}
