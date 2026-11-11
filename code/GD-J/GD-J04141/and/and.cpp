#include<bits/stdc++.h>
using namespace std;
int n,m,a[200010],mx=-0x3f3f3f;
void qf(int x,int cnt,int qfz){
	if(cnt==m){
		mx=max(mx,qfz);
		return;
	}for(int i=x+1;i<=n;i++){
		qf(i,cnt+1,qfz&a[i]);
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)qf(i,1,a[i]);
	cout<<mx;
	return 0;
} 
