#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m,a[N],maxn=-1;
bool cmp(int x,int y){
	return x>y;
}int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
		maxn=max(maxn,a[i]);
	}sort(a,a+n,cmp);
	if(m==1) cout<<maxn;
	else cout<<a[m-1];
	return 0;
}
