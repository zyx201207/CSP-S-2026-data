#include<bits/stdc++.h>
using namespace std;
int n,m,a[200010],ans;
int b[200010],l;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=30;i>=0;i--){
		l=0;
		int vl=(1<<i);
		for(int j=1;j<=n;j++){
			if(a[j]&vl)b[++l]=a[j];
		}
		if(l>=m){
			for(int j=1;j<=l;j++){
				a[j]=b[j];
			}
			n=l;
			ans+=vl;
		}
	}
	cout<<ans;
	return 0;
}
