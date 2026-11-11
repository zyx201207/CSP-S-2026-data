#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#include<cstring>
#include<queue>
#include<stack>
#include<map>
using namespace std;
int n,m,t1,t2,ans,a[10000001];
string s;
int main(){

	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){int x;cin>>x;ans=max(x,ans);}
	cout<<ans;
	return 0;
}
