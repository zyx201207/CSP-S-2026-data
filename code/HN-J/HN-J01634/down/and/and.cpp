#include <bits/stdc++.h>
using namespace std;
int n,m;
long long a[200005],sum;
void True(long long cnt,int c,int t) {
	if(c>n) return ;
	if(t==m) {
		sum=max(sum,cnt);
		return ;
	}
	True(cnt,c+1,0);
	if(cnt==-1) cnt=a[c];
	True(cnt&a[c],c+1,t+1);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) {
		cin>>a[i];
	}
	True(-1,1,0);
	cout<<sum;
	return 0;
} 
