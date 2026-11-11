#include<iostream>
#include<iomanip>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#include<set>
#include<map>
#define LL long long
const int N=1e5+10;
const int Inf=0x3f3f3f3f;
using namespace std;
LL n,m,a[N],ans; 
bool fl;
void dfs(LL sum,LL st,LL lst){
	if(st==m){
		ans=max(ans,sum);
		return;
	}
	for(int i=lst+1;i<=n;i++){
//		if(a[i]==a[lst]){
//			ans=max(ans,sum);
//			continue;
//		}
		dfs(sum&a[i],st+1,i);
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=i-1)fl=1;
	}
	if(!fl&&m>n/2){
		cout<<0;
		return 0;
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		dfs(a[i],1,i);
	}cout<<ans;
	return 0;
}


