#include <bits/stdc++.h>
using namespace std;
priority_queue<long long>a; 

bool cmp(long long x,long long y){
	return x>y;
}

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m,sum=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		long long x;
		cin>>x;
		a.push(x);
	}
	if(m==1){
		cout<<a.top();
		return 0;
	}
	sum=a.top();
	a.pop();
	for(int i=2;i<=m;i++){
		sum=sum&a.top();
		a.pop();
	}
	cout<<sum;
	return 0;
}
