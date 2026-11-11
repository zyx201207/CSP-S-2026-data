#include<bits/stdc++.h>
using namespace std;
int n,m,a[202020],l[202020][4],ans = -10086;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i<=n;i++)cin>>a[i];
	int li = -1,lj = -1,lk = -1;
	for(int i = 1;i<=n;i++){
		for(int j = 1;j<=n;j++){
			if((a[i] & a[j])>ans && i!=j){
				ans = a[i]&a[j];
				li = i;
				lj = j;
			}
		}
	}
	a[li] = 0;
	a[lj] = 0;
	a[0] = ans;
	cout<<ans<<' ';
	ans = -10086;
	for(int i = 3;i<=m;i++){
		for(int j = 1;j<=n;j++)if(a[j] & a[0]>=ans && a[j]!=0){
			ans = a[j]&a[0];
			cout<<ans<<' '<<a[j]<<' '<<a[0]<<endl;
			lk = j;
		}
		if(lk != 0)a[lk] = 0;
		lk = -1;
		a[0] = ans;
		ans = -10086;
	}
	cout<<a[0];
	return 0;
}