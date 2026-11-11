#include <iostream>
using namespace std;
int n,m,a[200005],ans;
bool vis[200005];
void x(int sum,int d){
	if(d==0){
		ans=max(ans,sum);
		return;
	}
	for(int i=0;i<n;i++){
		if(!vis[i]){
			vis[i]=1;
			x(sum&a[i],d-1);
			vis[i]=0;
		}
	}
}
int main(){
	freopen(and.in,"r",stdin);
	freopen(and.out,"w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++)cin>>a[i];
	for(int i=0;i<n;i++){
		vis[i]=1;
		x(a[i],m-1);
		vis[i]=0;
	}
	cout<<ans;
	return 0;
}
