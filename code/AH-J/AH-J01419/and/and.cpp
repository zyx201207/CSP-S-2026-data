#include<bits/stdc++.h>
using namespace std;
int a[200005];
bool cmp(int a1,int a2){
	return a1>a2;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	int cnt=a[1];
	for(int i=2;i<=m;i++){
		cnt&=a[i];
	}
	cout<<cnt;
	return 0;
} 
