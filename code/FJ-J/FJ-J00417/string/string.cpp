#include <bits/stdc++.h>
using namespace std;
struct T{
	long long x;
	char c;
}a[200010];
int n;
long long sum=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i].x>>a[i].c;
	int l=1,r=n;
	while(l<=r){
		if(a[l].x<=a[r].x){
			if(a[l].c!=a[r].c) sum+=a[l].x;
			a[r].x-=a[l++].x;
		}
		else{
			if(a[l].c!=a[r].c) sum+=a[r].x;
			a[l].x-=a[r--].x;
		}
	}
	cout<<sum;
	return 0;
}
