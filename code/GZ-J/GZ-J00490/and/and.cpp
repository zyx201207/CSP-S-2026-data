//GZ-J00490 遵义市第十二中学 黄正垚
#include <bits/stdc++.h>
using namespace std;
int max1=-1e9,cnt;
int a[1004];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cnt=a[i]^a[j];
			max1=max(max1,cnt);
		}
	}cout<<max1;
	return 0;
}

