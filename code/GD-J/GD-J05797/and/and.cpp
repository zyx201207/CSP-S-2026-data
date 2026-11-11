#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],minn=0;
bool cmp(int a,int b){
	return a>b;
}
void baoli(int s,int cnt,int chen){
	if(chen==m)  minn=max(minn,cnt);
	for(int i=s+1;i<=n;i++){
		if(cnt==0){
			baoli(i,a[i],chen+1);
		}else{
			baoli(i,a[i]&cnt,chen+1);
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.in","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(n>2000){
		sort(a+1,a+n+1,cmp);
		long long cnt=a[1];
		for(int i=2;i<=m;i++){
			cnt=cnt&a[i];
		}
		cout<<cnt;
	}else{
		baoli(0,0,0);
		cout<<minn;
	}
}
