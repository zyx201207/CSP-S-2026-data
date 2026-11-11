#include<bits/stdc++.h>
using namespace std;
const int N 2e5+10;
itn n,m,maxa = -1;
int a[N];
vector<int> v;
int calc(){
	
}
itn dfs(int x){
 if(k == m){
	int res = calc;
	return max(ret1,ret2);
 }
 if(m-k<=n-x+1){
	v.push_back (a[x]);
	return dfs(x+1);
	v.pop();
 }else{
	int ret1=dfs(x+1);
	v.push_back a[x];
	int ret2=dfs(x+1);
	return res
 }
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scarf("%d%d",&n,&m)
	v.push(5);
	v.push(5);
	v.push(13);
	cin>>n>>n;
	for(int i = 1;i<=n;i++
{
		cin>>a[i];
		scarf("%d",&a[i]);
		if(a[i]>=maxa){
			maxa = a[i];
		}
}	
	return 0;
}