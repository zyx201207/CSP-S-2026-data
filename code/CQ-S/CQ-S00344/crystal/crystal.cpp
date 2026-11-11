#include <iostream>
#include <algorithm>
using namespace std;
const int N=5e5+10;
int n;
long long m;
long long a[N],s[N];
bool f(int x){
	for(int i=1;i<=n-x+1;i++){
		long long x1=a[i+x-1]*x;
		long long x2=s[i+x-1]-s[i-1];
		if(x1-x2<=m) return 1;
	}
	return 0;
} 
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
	}
	int l=1,r=n;
	while(l<r){
		int mid=(l+r+1)>>1;
		if(f(mid)){
			l=mid;
		}else{
			r=mid-1;
		}
	}
	cout<<l;
	return 0;
} 
/*
5 5
1 2 4 8 9

5 8
-3 -1 2 2 7

Oct31==Dec25?
*/
