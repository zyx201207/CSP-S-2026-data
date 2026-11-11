//GZ-J00705 遵义市第十六中学 赵思杰 
#include<bits/stdc++.h>
using namespace std;
const long long N=200005;
bool cmp(int x,int y){
	if(x>=y) return x>y;
}
int main(){
	freopen("string.in",r,stdin);
	freopen("string.out",w,stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	long long a[N];
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n,cmp);
	cout<<a[m/2];
	return 0;
} 
