//GZ-J00289 周林学校 肖杭 
#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("and5.in","r",stdin);
	freopen("and5.out","w",stdout);
    int n,m,a[200005],d;
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1,greater<int>());
    d=a[1];
    for(int i=2;i<=m;i++)d=d&a[i];
	cout<<d;
	return 0;
}

