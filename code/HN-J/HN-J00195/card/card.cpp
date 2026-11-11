#include<iostream>
#include<queue>
#define int long long
using namespace std;
queue<int>q1,q2;
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0); 
	int n,m;
	cin>>n>>m;
	int num[m+1]={0};
	for(int i=1,a;i<=n;i++){
		cin>>a;
		num[a]++;
		if(i==n)num[a]=n;
	}
	for(int i=1;i<=m;i++)cout<<num[i]<<' ';
	return 0;
}
