#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
using namespace std;
long long n,m,a[500005],b[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	//for(int i=1;i<=n;i++) cout<<a[i]<<" ";
	//b[1]=0;
	for(int i=1;i<=n;i++){
		if((b[i-1]+(a[i]-a[i-1])*(i-1))<=m) b[i]=b[i-1]+(a[i]-a[i-1])*(i-1);
		else{
			cout<<(i-1)<<endl;
			return 0;
		}
	}
	return 0;
}
