#include <bits/stdc++.h>
using namespace std;
bool cmp(int b,int c){
	return b>c;
}
int yv(int x,int y){
	int z=max(x,y);
	int k=1;
	while (k<z){
		k*=2;
	}
	int s=0;
	while (k>=1){
		k/=2;
		if (x>=k&&y>=k) s+=k;
		if (x>=k) x-=k;
		if (y>=k) y-=k;
	}
	return s;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int m,n,a[200010]={0},s;
	cin >> n >> m;
	for (int i=1;i<=n;i++) cin >> a[i];
	sort(a+1,a+1+n,cmp);
	s=a[1];
	for (int i=2;i<=m;i++){
		s=yv(s,a[i]);
	}
	cout << s;
	return 0;
}
