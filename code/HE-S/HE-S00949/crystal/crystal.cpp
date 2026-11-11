#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],arr[500005],c,cnt;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i=0;i<n;i++){
		cin >> a[i];
	}
	sort(a,a+n,cmp);
	int l=a[0]-a[1];
	c=m/l;
	int c1=1;
	while(c>0){
		if(c<c1) break;
		c-=c1;
		c1++;
		cnt++;
	}
	cout << cnt;
	return 0;
}
