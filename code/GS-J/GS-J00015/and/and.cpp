#include<iostream>
#include<algorithm>
using namespace std;
int n,m,a[200005];

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int ans=-1;
	for(int i=1;i<=m;i++){
		ans&=a[i];
	}
	for(int i=1;i<=n-m;i++){
		int oans=-1;
//		oans|=(~a[i]);
//		oans&=a[i+m];
//		ans=max(ans,oans);
		for(int j=1;j<=m;j++){
			oans&=a[i+j];
		}
		ans=max(ans,oans);
	}
	cout<<ans;
	return 0;
}
