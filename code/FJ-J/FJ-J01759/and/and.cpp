#include<bits/stdc++.h>
using namespace std;
const int M= 2e5+5;
long long num[M];
int n,m; 
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>num[i];
	}
	int a=num[1];
	int b=num[3];
	cout<<a + b;
}
