//GZ-J00430 贵阳市第一实验中学 晏锦桐
#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,m;
long long a[N];
bool cmp(long long x,long long y){
	int sx=0,sy=0;
	long long tx=x,ty=y;
	while(tx){
		sx+=tx%2;
		tx/=2;
	}
	while(ty){
		sy+=ty%2;
		ty/=2;
	}
	return sx>sy||sx==sy&&x>y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	int ans=a[1];
	for(int i=2;i<=m;i++){
		ans=ans&a[i];
	}
	cout<<ans;
	return 0;
}
