#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int n,m,cnt=0,ans=0,a[]={},b=0;
	cin >> n >> m;
	for(int i=0;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			cin >> a[i];	
			cnt+=a[i];
			ans=cnt-a[i];
			cout << ans/12;
		} 
	}
	return 0;
}

