#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=1e8+10;
LL n,m;
int a[N];
int middle;
int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n; i++) cin>>a[i];
	sort(a+1,a+n+1);
	if(n%2==0) middle=a[n/2];
	else       middle=a[n/2-1];
//----------------------华丽的分界线--------------------------
	int count=1;
	for(int i=1;i<=n;i++) {
		if(a[i]>middle) break;
		if(a[i]<=middle) {
			a[i]++;
			count++;
		}
		if(a[i]==middle) i++;
		if(count==m) break;
	}
	sort(a+1,a+n+1);
	int sum=1;
	for(int i=1;i<=n;i++){
		if(a[i]=a[i+1])	sum++;
	}
	cout<<sum-1;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

//求通过（*＾-＾*）（*＾-＾*）o(*^▽^*)┛ 
