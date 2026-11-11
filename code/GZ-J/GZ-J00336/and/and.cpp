//姓名：赵梦砚西 准考证号：GZ-J00336 学校：贵阳市第十八中学
#include<bits/stdc++.h>
using namespace std;
long long a[1000005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m,zd=0;
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+n,a+n+1);
	for(long long i=1;i<=n;i++){
	    zd=a[n]^a[n-1];
	}
	cout<<zd;
	return 0;
}
