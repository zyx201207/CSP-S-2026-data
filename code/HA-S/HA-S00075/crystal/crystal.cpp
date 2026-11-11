#include<iostream>
#include<algorithm>
#define int long long
using namespace std;
int a[500005],c[500005];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	int Left=1,Right=1,Answer=0,Sum=a[1];
	while(Right+1<=n){
		Right++;
		Sum+=a[Right];
		while(a[Right]*(Right-Left+1)-Sum>m){
			Sum-=a[Left];
			Left++;
		}
		Answer=max(Right-Left+1,Answer);
	}
	cout<<Answer;
	return 0;
}
