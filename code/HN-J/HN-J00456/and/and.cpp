#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
	return x>y;
}
long long sum,n,m,a[100010];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
		cin>>n>>m;
		for(long long i=1;i<=n;i++){
			cin>>a[i];
		}
		sort(a+1,a+n+1,cmp);
		sum=a[1];
	   for(long long i=2;i<=m;i++){
	   	sum=sum&a[i];
	   }
	   cout<<sum;

	   	   return 0;
}
