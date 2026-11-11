#include<bits/stdc++.h>
using namespace std;
priority_queue<int> dxd;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	long long n,m,dxd2;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		int num;
		cin>>num;
		dxd.push(num);
	}
	for(int i=0;i<m;i++){
		dxd2=dxd.top();
		dxd.pop();
	}
	cout<<dxd2;
	return 0;
}

