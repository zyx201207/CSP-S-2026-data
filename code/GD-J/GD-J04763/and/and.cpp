#include<bits/stdc++.h>
using namespace std;
const int N=200050;
bool b[N];
int a[N];
int n,m;
int ans;
bool check(int p){//判断第p位能否为1 
	int cnt=0;
	for(int i=1;i<=n;i++){
		if(!b[i])continue;
		if((a[i]>>(p-1))&1)cnt++; 
	}
	return cnt>=m;
}
void cut(int p){
	for(int i=1;i<=n;i++){
		if(!b[i])continue;
		if(!((a[i]>>(p-1))&1))b[i]=0;
	}
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	memset(b,1,sizeof b);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=30;i>=1;i--){
		if(check(i)){
			ans+=(1<<(i-1));
			cut(i);
		}
	}
	cout<<ans;
	return 0;
}
