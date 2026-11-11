#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m,a[N];
vector<int>v;
int count(int x){
	int cnt=0;
	for(int val:v)if(val&x)cnt++;
	return cnt;
}
void del(int x){
	vector<int>tmp;
	for(int val:v)if(val&x)tmp.push_back(val);
	v=tmp;
}
void work(){
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i],v.push_back(a[i]);
	int ans=0;
	for(int i=30;i>=0;i--)if(count(1<<i)>=m){
		del(1<<i);
		ans+=(1<<i);
	}
	cout<<ans;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin.tie(0)->sync_with_stdio(false);
	work();
	return 0;
}
