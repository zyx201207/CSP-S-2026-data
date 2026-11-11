#include <bits/stdc++.h>
using namespace std;
const int N=2e5+1;
int n,m;
struct node{
	int cnt,x,len;
	int a[40];
}a[N];
int len=0;
bool cmp(node x,node y){
	if(x.cnt!=y.cnt) return x.cnt>y.cnt;
//	return x.len-x.cnt<y.len-y.cnt;
//	else if(x.len!=y.len) return 
	return x.x>y.x;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i].x;
		int x=a[i].x;
		int k=0;
		while(x>0){
			a[i].a[++k]=x%2;
			if(x%2==1) a[i].cnt++;
			x/=2;
		}
		a[i].len=k;
		len=max(len,k);
	}
	sort(a+1,a+n+1,cmp);
	int ans=a[1].x;
	for(int i=2;i<=m;i++) ans=ans&a[i].x;
	cout<<ans;
	return 0;
}

