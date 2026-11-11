#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 1e6+10;
long long a[N];
int main(int argc, char** argv) {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int m,n,ans=0;
	cin>>n>>m;
	for(int i = 0;i < n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	for(int i = 29;i >=0;i--){
		if((a[n-1] >> i) ==0){
			continue;
		}
		int x = a[n-m] >>i & 1;
		if(x==1){
			ans+=1<<i;
		}
	}
	cout<<ans;
	return 0;
}