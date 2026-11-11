//华东师范大学附属贵阳学校 陈睿阳 GZ-J00418 
#include <bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,m,ma=0;
int a[N];
void xs(int wz,int k,int ans){
	if (k==m){
		ma=max(ma,ans);
		return;
	}
	if (wz>n) return;
	for (int i=0;i<=1;i++){
		if (i==0) xs(wz+1,k,ans);
		else {
			xs(wz+1,k+1,ans&a[wz]);
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m;
	for (int i=1;i<=n;i++){
		cin >> a[i];
	}
	xs(1,0,0x3f);
	cout << ma;
	return 0;
}
