//GZ-J00346ª∆≤≈ËÚ
#include<iostream>
#include<algorithm>

using namespace std;
const int N = 5e6 + 5;
int a[N],n,m;

bool cmp(int x,int y){
	return x > y;
}

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);

	cin>>n>>m;
	for(int i = 0;i<n;i++) cin>>a[i];

	sort(a,a+n,cmp);

	int ans = a[0];
	for(int i = 1;i<m;i++){
		ans = ans & a[i];
	}
	cout<<ans;
	return 0;
}
