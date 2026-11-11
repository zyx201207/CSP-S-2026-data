#include<bits/stdc++.h>
using namespace std;
long long a[100005];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin >> n >> m;
	for(int i=0;i<n;i++)
		{
			cin >> a[i];
		}
		sort(a,a+n,cmp);
	long long ans=a[0];
	for(int i=1;i<m;i++)
		{
			ans=ans&a[i];
		}
	cout << ans;
    return 0;
}
