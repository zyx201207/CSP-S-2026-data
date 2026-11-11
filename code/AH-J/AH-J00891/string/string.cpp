#include<iostream>
#include<cmath>
using namespace std;
const int N=2e5+8;
struct A{
	int cnt;
	char c;
}a[N];
int n;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].cnt>>a[i].c;
	}
	int l=1,r=n;
	long long count=0;
	while(l<r){
		int minn=min(a[l].cnt,a[r].cnt);
		if(a[l].c!=a[r].c) count=count+minn;
		a[l].cnt-=minn;
		a[r].cnt-=minn;
		if(a[l].cnt==0) l++;
		if(a[r].cnt==0) r--;
	}
	cout<<count;
	return 0;
}
