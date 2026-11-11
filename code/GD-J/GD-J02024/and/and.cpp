#include<bits/stdc++.h>

using namespace std;

const int N=2e5+10;
bool cmp(int &x,int &y){
	return x>y;
}
int a[N];

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1,cmp);
	long long sum=a[1];
	for(int i=1;i<=m;i++)sum=(sum&a[i]);
	cout<<sum;
	
	return 0; 
} 
